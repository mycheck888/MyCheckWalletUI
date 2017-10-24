//
//  AddCreditCardViewController.swift
//  Pods
//
//  Created by elad schiller on 7/23/17.
//  Copyright (c) 2017 __MyCompanyName__. All rights reserved.
//
//  This file was generated by the Clean Swift Xcode Templates so
//  you can apply clean architecture to your iOS and Mac projects,
//  see http://clean-swift.com
//

import UIKit
import MyCheckCore
internal protocol AddCreditCardViewControllerDelegate : class{
    
    func recivedError(_ controller: AddCreditCardViewController , error:NSError)
    
    func addedNewPaymentMethod(_ controller: AddCreditCardViewController ,token:String)
    
    func canceled()
}


protocol AddCreditCardDisplayLogic: class
{
    
    func updateField(viewModel: AddCreditCard.TextChanged.ViewModel)
    
    func formSubmitionResponse(viewModel: AddCreditCard.SubmitForm.ViewModel)
    
    func changeLoadingView(viewModel: AddCreditCard.StateChange.ViewModel)
    
}

open class AddCreditCardViewController: MCViewController
{
    
    
    @IBOutlet weak var errorHeight: NSLayoutConstraint!
    
    internal weak var containerHeight: NSLayoutConstraint?
    @IBOutlet weak var checkboxLabel: UILabel!
    @IBOutlet weak var checkbox: UIButton!
    
    @IBOutlet internal weak var applyButton: UIButton!
    @IBOutlet internal var typeImage: UIImageView!
    @IBOutlet internal var creditCardNumberField: UITextField!
    @IBOutlet internal var dateField: UITextField!
    @IBOutlet internal var cvvField: UITextField!
    @IBOutlet internal var zipField: UITextField!
    @IBOutlet weak var cancelBut: UIButton!
  @IBOutlet weak var navbar: UIView!

    @IBOutlet internal var creditCardUnderline: UIView!
    @IBOutlet internal var dateUnderline: UIView!
    @IBOutlet internal var cvvUnderline: UIView!
    @IBOutlet internal var zipUnderline: UIView!
    @IBOutlet internal weak var errorLabel: UILabel!
    @IBOutlet weak var navBar: UINavigationBar!
    
    internal var underlineForField : [UITextField : UIView]?
    internal var activityView : UIActivityIndicatorView = UIActivityIndicatorView(activityIndicatorStyle: .gray)
    
    weak  var delegate : AddCreditCardViewControllerDelegate?
    
    var interactor: AddCreditCardBusinessLogic?
    var router: (NSObjectProtocol & AddCreditCardRoutingLogic & AddCreditCardDataPassing)?
    
    // MARK: Object lifecycle
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?)
    {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
        setup()
    }
    
    required public init?(coder aDecoder: NSCoder)
    {
        super.init(coder: aDecoder)
        setup()
    }
    
    // MARK: Setup
    
    private func setup()
    {
        let viewController = self
        let interactor = AddCreditCardInteractor()
        let presenter = AddCreditCardPresenter()
        let router = AddCreditCardRouter()
        viewController.interactor = interactor
        viewController.router = router
        interactor.presenter = presenter
        presenter.viewController = viewController
        router.viewController = viewController
        router.dataStore = interactor
    }
    
    // MARK: Routing
    
    override open func prepare(for segue: UIStoryboardSegue, sender: Any?)
    {
        if let scene = segue.identifier {
            let selector = NSSelectorFromString("routeTo\(scene)WithSegue:")
            if let router = router, router.responds(to: selector) {
                router.perform(selector, with: segue)
            }
        }
    }
    
    // MARK: View lifecycle
    
    override open func viewDidLoad()
    {
        super.viewDidLoad()
        //setting up the UI
        underlineForField = [creditCardNumberField : creditCardUnderline , dateField : dateUnderline , cvvField : cvvUnderline , zipField : zipUnderline]
        
        addNextButtonOnKeyboard(creditCardNumberField, action: #selector(nextPressed(_: )))
        addNextButtonOnKeyboard(dateField, action: #selector(nextPressed(_: )))
        addNextButtonOnKeyboard(cvvField, action: #selector(nextPressed(_: )))
        
        //setting up UI and updating it if the user logges in... just incase
        setupUI()
        let nc = NotificationCenter.default
        nc.addObserver(self, selector: #selector(AddCreditCardViewController.setupUI), name: NSNotification.Name(rawValue: Wallet.loggedInNotification), object: nil)
        
    }
    
   
    
    
    // MARK private methods
    //MARK: - private functions
    internal func setupUI(){
      if let navbar = navbar{
        navbar.backgroundColor = LocalData.manager.getColor("managePaymentMethodscolorsheaderBackground", fallback: navbar.backgroundColor!)
      }

        self.creditCardNumberField.placeholder = LocalData.manager.getString("addCreditcardNumPlaceHoldar")
        self.cvvField.placeholder = LocalData.manager.getString("addCreditcvvPlaceholder" , fallback: self.cvvField.placeholder)
        self.dateField.placeholder = LocalData.manager.getString("addCreditcardDatePlaceHoldar" , fallback: self.dateField.placeholder)
        self.zipField.placeholder = LocalData.manager.getString("addCreditzipPlaceHolder" , fallback: self.zipField.placeholder)
        applyButton.setTitle( LocalData.manager.getString("addCreditapplyAddingCardButton" , fallback: self.applyButton.title(for: UIControlState())) , for: UIControlState())
        applyButton.setTitle( LocalData.manager.getString("addCreditapplyAddingCardButton" , fallback: self.applyButton.title(for: UIControlState())) , for: .highlighted)
        
        cancelBut.setTitle( LocalData.manager.getString("addCreditcancelAddingCardButton" , fallback: self.cancelBut.title(for: UIControlState())) , for: UIControlState())
        cancelBut.setTitle( LocalData.manager.getString("addCreditcancelAddingCardButton" , fallback: self.cancelBut.title(for: UIControlState())) , for: .highlighted)
        
        //setting colors
        navBar.barTintColor = LocalData.manager.getColor("managePaymentMethodscolorsheaderBackground", fallback: navBar.backgroundColor!)
        
        errorLabel.textColor = LocalData.manager.getColor("addCreditColorsinputError", fallback: errorLabel.textColor!)
        applyButton.backgroundColor = LocalData.manager.getColor("addCreditColorsapplyBackgroundColor", fallback: UIColor.white)
        applyButton.layer.cornerRadius = 8
        applyButton.setTitleColor(LocalData.manager.getColor("addCreditColorsapplyButtonText", fallback: UIColor.white), for: UIControlState())
        cancelBut.layer.cornerRadius = 8
        
        cancelBut.backgroundColor = LocalData.manager.getColor("addCreditColorscancelColor", fallback: UIColor.white)
        cancelBut.setTitleColor(LocalData.manager.getColor("addCreditColorscancelButtonText", fallback: UIColor.white), for: UIControlState())
        
        
        for (key , value) in underlineForField!{
            key.textColor = LocalData.manager.getColor("addCreditColorsfieldText", fallback: key.textColor!)
            key.placeholderColor(LocalData.manager.getColor("addCreditColorshintTextColor" , fallback: UIColor.lightGray))
            value.backgroundColor = LocalData.manager.getColor("addCreditColorsinputError", fallback: value.backgroundColor!)
        }
        self.activityView.center=CGPoint(x: self.view.center.x, y: self.view.center.y + 104)
        self.activityView.isHidden = true
        self.activityView.hidesWhenStopped = true
        self.view.addSubview(activityView)
        
    

    }
    
    
   
    
    
    
}

extension AddCreditCardViewController: AddCreditCardDisplayLogic{
    
    func changeLoadingView(viewModel: AddCreditCard.StateChange.ViewModel) {
        let UIEnabled = viewModel.showLoadingView
        
        applyButton.isEnabled = UIEnabled
        cancelBut.isEnabled = UIEnabled
        self.creditCardNumberField.isUserInteractionEnabled = UIEnabled
        self.dateField.isUserInteractionEnabled = UIEnabled
        self.cvvField.isUserInteractionEnabled = UIEnabled
        self.zipField.isUserInteractionEnabled = UIEnabled

        
        if viewModel.showLoadingView{
            self.activityView.startAnimating()
        }else{
        self.activityView.stopAnimating()
        }
    }
    
    
    func formSubmitionResponse(viewModel: AddCreditCard.SubmitForm.ViewModel) {
        switch viewModel {
        case .success:
            if let delegate = self.delegate{
                delegate.addedNewPaymentMethod(self, token:"")

            }
        case .fail(let failObJ):
            self.showError(errorStr: failObJ.errorMessage)
            for fieldPresentation in failObJ.fieldPresentations{
            
                switch fieldPresentation.FieldType {
                case .number:
                    creditCardNumberField.textColor = fieldPresentation.textColor
                    creditCardUnderline.backgroundColor = fieldPresentation.underlineColor
                case .date:
                    dateField.textColor = fieldPresentation.textColor
                    dateField.backgroundColor = fieldPresentation.underlineColor
                case .cvv:
                    cvvField.textColor = fieldPresentation.textColor
                    cvvField.backgroundColor = fieldPresentation.underlineColor
                case .zip:
                    zipField.textColor = fieldPresentation.textColor
                    zipField.backgroundColor = fieldPresentation.underlineColor

                    
                }}

        }
    }
    
    
    func updateField(viewModel: AddCreditCard.TextChanged.ViewModel) {
        var field: UITextField? = nil
        switch viewModel.type{
        case .number:
            field = self.creditCardNumberField
        case .date:
             field = self.dateField
        case .cvv:
             field = self.cvvField
        case.zip:
             field = self.zipField
        }
        let underline = underlineForField?[field!]

        underline?.backgroundColor = viewModel.underlineColor
        field?.textColor = viewModel.textColor
        field?.text = viewModel.text
        
        
        //setting image
        let bundle =  MCViewController.getBundle( Bundle(for: AddCreditCardViewController.classForCoder()))
        switch viewModel.cardTypeIconUpdate{
        case .showPlaceholder:
            if self.isMember(of: AddCreditCardViewController.self) {
                typeImage.image = UIImage(named: "no_type_card_1" , in: bundle, compatibleWith: nil)
            }else{
                typeImage.image = UIImage(named: "no_type_card" , in: bundle, compatibleWith: nil)
            }
        case.updateCardTypeImage(let url):
            typeImage.kf.setImage(with: url)
        }
        
    }
}

// MARK - private methods
extension AddCreditCardViewController{
    
    
    fileprivate func addNextButtonOnKeyboard(_ field: UITextField , action: Selector)
    {
        let doneToolbar: UIToolbar = UIToolbar(frame: CGRect(x: 0, y: 0, width: 320, height: 50))
        doneToolbar.barStyle = UIBarStyle.blackTranslucent
        
        let flexSpace = UIBarButtonItem(barButtonSystemItem: UIBarButtonSystemItem.flexibleSpace, target: nil, action: nil)
        let done: UIBarButtonItem = UIBarButtonItem(title: "Next", style: UIBarButtonItemStyle.done, target: self, action: action)
        
        let items = [flexSpace , done]
        
        
        doneToolbar.items = items
        doneToolbar.sizeToFit()
        
        field.inputAccessoryView = doneToolbar
        
    }
    
    @objc fileprivate func nextPressed(_ sender: UIBarButtonItem){
        if creditCardNumberField.isFirstResponder{
            dateField.becomeFirstResponder()
        } else if dateField.isFirstResponder{
            cvvField.becomeFirstResponder()
        } else if cvvField.isFirstResponder{
            zipField.becomeFirstResponder()
        }
    }
    
    fileprivate func showError(errorStr: String){
        self.errorLabel.text = errorStr
        if errorStr.characters.count == 0 {
            UIView.animate(withDuration: 0.3, animations: {
                self.errorHeight.constant = 0
                self.view.layoutIfNeeded()
                if let containerHeight =  self.containerHeight{
                    containerHeight.constant = 250.0
                }
                if let parent = self.parent {
                    parent.view.layoutIfNeeded()
                }
                
            })
            return;
        }
        self.errorLabel.alpha = 0.0
        //animating the error view in ... showing the error for a few seconds and removing again
        
        UIView.animate(withDuration: 0.3, animations:  {
            self.errorHeight.constant = 25.0
            if let containerHeight =  self.containerHeight{
                containerHeight.constant = 275.0
            }
            self.errorLabel.alpha = 1.0
            self.parent?.view.layoutIfNeeded()
            
            self.view.layoutIfNeeded()
            
            delay(0.3 + LocalData.manager.getDouble("ValueserrorTime", fallback: 7.0)){
                UIView.animate(withDuration: 0.3, animations: {
                    self.errorHeight.constant = 0
                    if let containerHeight =  self.containerHeight{
                        containerHeight.constant = 250.0
                    }
                    self.errorLabel.alpha = 0.0
                    self.view.layoutIfNeeded()
                    if let parent = self.parent {
                        
                        parent.view.layoutIfNeeded()
                    }
                } , completion: { finished in
                    self.errorLabel.text  = ""
                    
                })
            }
        }, completion: { finished in
            
        })
    }
}
