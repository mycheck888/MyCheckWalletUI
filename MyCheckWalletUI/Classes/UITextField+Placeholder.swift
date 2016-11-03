//
//  UITextField+Placeholder.swift
//  Pods
//
//  Created by elad schiller on 11/2/16.
//
//

import Foundation

extension UITextField {
    func placeholderColor(color: UIColor){
        if let placeholder = placeholder {
        self.attributedPlaceholder = NSAttributedString(string:placeholder,
                                                               attributes:[NSForegroundColorAttributeName: color])
        }
    }
}
