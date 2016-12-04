//
//  CreditCardView.swift
//  Pods
//
//  Created by Mihail Kalichkov on 9/29/16.
//
//

import UIKit

internal protocol CreditCardViewDelegate : class{
    func deletedPaymentMethod(method : PaymentMethod)
    func setPaymentAsDefault()
  func showActivityIndicator(show: Bool)
}

internal class CreditCardView: UIView, UIGestureRecognizerDelegate {
    
    var paymentMethod : PaymentMethod?
    var checboxButton : UIButton?
    var editMode = false
    var delegate : CreditCardViewDelegate?
    
    
    var creditCardNumberlabel: UILabel?
    var expirationDateLabel: UILabel?
    var backgroundButton: UIButton?
    init(frame: CGRect, method: PaymentMethod){
        super.init(frame: frame)
      
      let bundle =  MCViewController.getBundle( NSBundle(forClass: MCAddCreditCardViewController.classForCoder()))

        self.userInteractionEnabled = true
        self.paymentMethod = method
        
         backgroundButton = UIButton(frame: CGRectMake(0, 0, 163, 102))
        if  let backgroundButton = backgroundButton{
        backgroundButton.addTarget(self, action: #selector(creditCardPressed(_:)), forControlEvents: .TouchUpInside)
        backgroundButton.setImage(self.setImageForType(method.issuer), forState: .Normal)
        backgroundButton.adjustsImageWhenHighlighted = false
        addSubview(backgroundButton)
        }
      
      if method.isSingleUse {
      let singleUseImg = UIImageView(image:UIImage(named: "singleUseBanner", inBundle: bundle, compatibleWithTraitCollection: nil) )
        singleUseImg.contentMode = .TopRight
        singleUseImg.frame = (backgroundButton?.frame)!
        addSubview(singleUseImg)
      }
        //credit card number label
        creditCardNumberlabel  = UILabel(frame: CGRectMake(10, 70, 80, 18))
        if let creditCardNumberlabel = creditCardNumberlabel {
        creditCardNumberlabel.textAlignment = NSTextAlignment.Center
        creditCardNumberlabel.textColor = UIColor.whiteColor()
        creditCardNumberlabel.font =  UIFont(name: creditCardNumberlabel.font.fontName, size: 9)
        if let lastFourDigits = method.lastFourDigits{
            creditCardNumberlabel.text = method.name
          }
        addSubview(creditCardNumberlabel)
            }
        //expiration date label
       expirationDateLabel = UILabel(frame: CGRectMake(112, 70, 30, 18))

        if let expirationDateLabel = expirationDateLabel{
        expirationDateLabel.textAlignment = NSTextAlignment.Center
        expirationDateLabel.textColor = UIColor.whiteColor()
        expirationDateLabel.font =  UIFont(name: expirationDateLabel.font.fontName, size: 9)
        if var year = method.expireYear, month = method.expireMonth{
            if year.characters.count > 2 {
                year = year.substringFromIndex(year.startIndex.advancedBy(2))
                
                expirationDateLabel.text = String(format: "%@/%@", month, year)
                addSubview(expirationDateLabel)
            }
            }
        }
        
        
        
        //default card checkbox
      
        self.checboxButton = UIButton(frame: CGRectMake(165, 0, 20, 20))
        self.checboxButton?.addTarget(self, action: #selector(checkboxPressed(_:)), forControlEvents: .TouchUpInside)
        self.checboxButton?.adjustsImageWhenHighlighted = false
        addSubview(self.checboxButton!)
        
        if ((self.paymentMethod!.isDefault) == true) {
            self.checboxButton?.setImage(UIImage(named: "v", inBundle: bundle, compatibleWithTraitCollection: nil)!, forState: .Normal)
            self.checboxButton?.hidden = false
        }else{
            self.checboxButton?.hidden = true
        }
    }
    
    func checkboxPressed(sender: UIButton!) {
        if editMode == true {
            MyCheckWallet.manager.deletePaymentMethod(self.paymentMethod!, success: {
                printIfDebug("payment method deleted")
                if let del = self.delegate{
                    del.deletedPaymentMethod(self.paymentMethod!)
                }
                }, fail: { (error) in
                    printIfDebug("did not delete payment")
            })
        }
    }
    
    func creditCardPressed(sender: UIButton!){
        if editMode == false {
            if self.paymentMethod?.isDefault == false {
                self.delegate?.showActivityIndicator(true)
                MyCheckWallet.manager.setPaymentMethodAsDefault(self.paymentMethod!, success: {
                  self.delegate?.showActivityIndicator(false)

                    printIfDebug("payment set as default")
                    if let del = self.delegate{
                        del.setPaymentAsDefault()
                        
                    }
                    }, fail: { (error) in
                      self.delegate?.showActivityIndicator(false)

                        printIfDebug("did not set payment as default")
                })
            }
        }
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        self.paymentMethod = nil
    }
    
    internal func getType(type : String) -> CreditCardType {
        switch type {
        case "visa":
            return CreditCardType.Visa
        case "mastercard":
            return CreditCardType.MasterCard
        case "discover":
            return CreditCardType.Discover
        case "amex":
            return CreditCardType.Amex
        case "jcb":
            return CreditCardType.JCB
        case "dinersclub":
            return CreditCardType.Diners
        case "maestro":
            return CreditCardType.Maestro
            
        default:
            return CreditCardType.Unknown
        }
    }
    
    internal func setImageForType( type: CreditCardType) -> UIImage{
        let bundle =  MCViewController.getBundle( NSBundle(forClass: MCAddCreditCardViewController.classForCoder()))
        switch type {
        case .MasterCard:
            return UIImage(named: "master_card_background", inBundle: bundle, compatibleWithTraitCollection: nil)!
        case .Visa:
            return UIImage(named: "visa_background", inBundle: bundle, compatibleWithTraitCollection: nil)!
        case .Diners:
            return UIImage(named: "diners_background", inBundle: bundle, compatibleWithTraitCollection: nil)!
        case .Discover:
            return UIImage(named: "discover_background", inBundle: bundle, compatibleWithTraitCollection: nil)!
        case .Amex:
            return UIImage(named: "amex_background", inBundle: bundle, compatibleWithTraitCollection: nil)!
        case .Diners:
            return UIImage(named: "diners_background", inBundle: bundle, compatibleWithTraitCollection: nil)!
        case .JCB:
            return UIImage(named: "jcb_background", inBundle: bundle, compatibleWithTraitCollection: nil)!
        case .Maestro:
            return UIImage(named: "maestro_background", inBundle: bundle, compatibleWithTraitCollection: nil)!
            
        default:
            return UIImage(named: "notype_background" , inBundle: bundle, compatibleWithTraitCollection: nil)!
        }
    }
    
    func toggleEditMode(){
        self.editMode = !self.editMode
        if self.editMode == true {
            let bundle =  MCViewController.getBundle( NSBundle(forClass: MCAddCreditCardViewController.classForCoder()))
            self.checboxButton?.setImage(UIImage(named: "delete", inBundle: bundle, compatibleWithTraitCollection: nil)!, forState: .Normal)
            self.checboxButton?.hidden = false
        }else{
            if self.paymentMethod!.isDefault == true {
                let bundle =  MCViewController.getBundle( NSBundle(forClass: MCAddCreditCardViewController.classForCoder()))
                self.checboxButton?.setImage(UIImage(named: "v", inBundle: bundle, compatibleWithTraitCollection: nil)!, forState: .Normal)
                self.checboxButton?.hidden = false
            }else{
                self.checboxButton?.hidden = true
            }
        }
    }
}
