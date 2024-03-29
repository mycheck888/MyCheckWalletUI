//
//  ApplePayView.swift
//  Pods
//
//  Created by elad schiller on 11/15/16.
//
//

import UIKit
import MyCheckCore

class ApplePayView: CreditCardView {
  
  
  override init(frame: CGRect, method: PaymentMethodInterface){
    super.init(frame: frame, method: method)
    self.expirationDateLabel?.removeFromSuperview()
    self.tempCardIcon.removeFromSuperview()
    let bundle =  MCViewController.getBundle( Bundle(for: MCAddCreditCardViewController.classForCoder()))
    let image = UIImage(named: "applePayBackground" , in: bundle, compatibleWith: nil)
    backgroundButton!.setBackgroundImage(image, for: .normal)
    self.creditCardNumberlabel?.removeFromSuperview()
  }
  required init?(coder aDecoder: NSCoder) {
    super.init(coder: aDecoder)
  }
  
  override func awakeFromNib() {
    super.awakeFromNib()
    //moving the label into position
    if let creditCardNumberlabel = self.creditCardNumberlabel{
      creditCardNumberlabel.textAlignment = NSTextAlignment.center;
      
      
    }
  }
  
  @IBAction override func creditCardPressed(_ sender: UIButton!){
    if let paymentMethod = self.paymentMethod , paymentMethod.isDefault == false {
        
        Wallet.shared.applePayController.changeApplePayDefault(to: true)
        printIfDebug("payment set as default")
        if let del = self.delegate{
            del.setPaymentAsDefault(method: paymentMethod)
            
        }
    }
    
  }
  
  
}
