//
//  MCCreditCardsViewController.swift
//  Pods
//
//  Created by Mihail Kalichkov on 9/29/16.
//
//

import UIKit

internal protocol MCCreditCardsViewControllerrDelegate {
    func backPressed()
}

internal class MCCreditCardsViewController: MCViewController , UIScrollViewDelegate, UIGestureRecognizerDelegate, CreditCardViewDelegate{

    @IBOutlet weak var editButton: UIBarButtonItem!
    @IBOutlet weak var scrollView: MCScrollView!
    var paymentMethods: Array<PaymentMethod>!
    var delegate : MCCreditCardsViewControllerrDelegate?
    var creditCards : NSMutableArray = []
    var editMode : Bool = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.setCrediCards()
        self.scrollView.delegate = self;
    }
    
    private func setCrediCards(){
        self.scrollView.frame = CGRect(x:self.scrollView.frame.origin.x, y:self.scrollView.frame.origin.y, width:self.scrollView.frame.width, height:100)
        
        UIView.animateWithDuration(0.4, animations: {
            self.scrollView.contentOffset = CGPointZero
        })
        
        let creditCardCount = self.paymentMethods.count
        
        let addCreditCardView = AddCreditCardView(frame: CGRectMake(0, 20, 168, 104) )
        self.scrollView.addSubview(addCreditCardView)
        
        for i in (0..<creditCardCount) {
            let method = self.paymentMethods[i]
            let cc = CreditCardView(frame: CGRectMake(193*CGFloat(i+1), 20, 164, 102), method: method)
            creditCards.addObject(cc)
            cc.delegate = self
            self.scrollView.addSubview(cc)
        }
        
        self.scrollView.contentSize = CGSize(width:CGFloat(creditCardCount+1)*193, height:self.scrollView.frame.height)
    }
    @IBAction func backPressed(_ sender: UIBarButtonItem) {
        self.delegate?.backPressed()
    }
    @IBAction func editPressed(_ sender: UIBarButtonItem) {
        //self.editMode ? self.editButton.title("Done", forState: .Normal) : self.editButton.setTitleTextAttributes("Edit", forState: .Normal)
        self.editMode = !self.editMode
        self.editButton.title = self.editMode ? "Done" : "Edit"
        
        for cc in creditCards as! [CreditCardView]{
            cc.toggleEditMode()
        }
    }
    
    func deletedPaymentMethod(){
        MyCheckWallet.manager.getPaymentMethods({ (array) in
            self.paymentMethods = array
            for cc in self.creditCards as! [CreditCardView]{
                cc.toggleEditMode()
            }
            self.setCrediCards()
            }, fail: { error in
                
        })
    }
}