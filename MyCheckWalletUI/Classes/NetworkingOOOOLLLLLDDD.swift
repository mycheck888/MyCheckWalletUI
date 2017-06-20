//
//import Foundation
//import UIKit
//import CoreData
//import MyCheckCore
//
////A number of error codes you might encounter
//public enum ErrorCodes {
//    ///A non JSON answer received from the server or parsing failed on the JSON passed.
//    static let badJSON = 971
//    /// The user is not logged in.
//    static let notLoggedIn = 972
//    ///No action can be made since a publishable key was not supplied.
//    static let MissingPublishableKey = 976
//    ///The SDK was not configured.
//    static let notConifgured = 977
//    ///Access token expired. A new one must be generated using login.
//    static let tokenExpired = 121
//    
//}
//
//internal class Networking {
//    
//    
//    //This property points to the singlton object. It should be used for calling all the functions in the class.
//    internal static let manager = Networking()
//    
//
//    var domain : String?
//    var PCIDomain: String?
//    var environment = Environment.sandbox
//    var refreshToken: String?
//    var publishableKey : String?
//    var token : String?
//
//    private var _UUID : String? = nil
//    private var UUID : String  {
//        get{
//            if let UUID = _UUID{
//                return UUID
//            }
//            _UUID  = NSUUID().uuidString
//            return _UUID!
//        } }
//    
//    
//    func configureWallet() {
//
//        Networking.shar
//        return  request(urlStr, method: .get, parameters: nil , success: { JSON in
//            
//            self.domain = JSON["Domain"] as? String
//            self.PCIDomain = JSON["PCI"] as? String
//            let langObj = JSON["lang"] as! NSDictionary
//            
//            let textsURL = langObj["en"] as! String
//            
//            
//            //getting the texts
//            self.request(textsURL, method: .get, parameters: nil , success: { txtJSON in
//                
//                
//                
//                
//                success(self.domain!, self.PCIDomain!, JSON, txtJSON)
//                }, fail: fail)
//            
//            
//            }, fail: fail)
//        
//    }
//    
//   
//    func getPaymentMethods( _ accessToken: String , success: @escaping (( [PaymentMethod] ) -> Void) , fail: ((NSError) -> Void)? ) -> Alamofire.Request?{
//        let params = [ "accessToken": accessToken]
//        
//        let urlStr = domain! + "/wallet/api/v1/wallet"
//        
//        return  request(urlStr , method: .get, parameters: params , success: { JSON in
//            var returnArray : [PaymentMethod] = []
//            
//            if  let methodsJSON = JSON["PaymentMethods"] as? NSArray{
//                
//                for dic in methodsJSON as! [NSDictionary]{
//                    if let method = PaymentMethod(JSON: dic){
//                      if let factory = Wallet.shared.getFactory(method.type){
//                      
//                      }
//                        returnArray.append(method)
//                    }
//                }
//                returnArray.sort(by: {$0.isSingleUse && !$1.isSingleUse}) //sorts temporary cards to be first in the list
//                success(returnArray)
//            }else{
//                if let fail = fail{
//                    fail(self.badJSONError())
//                }
//            }
//            
//            // success()
//            
//            }, fail: fail)
//    }
//    
//    func addCreditCard(_ rawNumber: String ,
//                       expireMonth: String ,
//                       expireYear: String ,
//                       postalCode: String ,
//                       cvc: String ,
//                       type: CreditCardType ,
//                       isSingleUse: Bool ,
//                       accessToken: String ,
//                       environment: Environment ,
//                       success: @escaping (( PaymentMethod ) -> Void) ,
//                       fail: ((NSError) -> Void)? ) -> Alamofire.Request?{
//        var params : Parameters = [ "accessToken" : accessToken , "rawNumber" : rawNumber , "expireMonth" : expireMonth , "expireYear" : expireYear , "postalCode" : postalCode , "cvc" : cvc , "cardType" : type.rawValue , "is_single_use" : String(describing: NSNumber(value: isSingleUse))]
//       
//      
//      
//        params["env"] = environment.getString()
//        return  request(PCIDomain! + "/PaymentManager/api/v1/paymentMethods/addCreditcard",
//                        method: .post,
//                        parameters: params ,
//                        encoding: JSONEncoding.default,
//                        addedHeaders: ["Content-Type":"application/json"]
//, success: { JSON in
//    
//            let methodJSON = JSON["pm"] as? NSDictionary
//            if let methodJSON = methodJSON{
//                success(PaymentMethod(JSON: methodJSON )!)
//            }else{
//                if let fail = fail{
//                    if let errormessage = JSON["message"] as? String{
//                        let errorWithMessage = NSError(domain: "error", code: 3 , userInfo: [NSLocalizedDescriptionKey : errormessage])
//                        fail(errorWithMessage)
//                    }
//                }
//            }
//            
//            
//            
//            }, fail: fail )
//    }
//    
//    func setPaymentMethodAsDefault( _ accessToken: String , methodId: String , success: @escaping (() -> Void) , fail: ((NSError) -> Void)? ) -> Alamofire.Request?{
//        let params = [ "accessToken": accessToken , "ID": methodId]
//        
//        let urlStr = domain! + "/wallet/api/v1/wallet/default"
//        
//        return  request(urlStr,  method: .post, parameters: params , success: { JSON in
//            success()
//            
//            }, fail: fail)
//    }
//    
//    func deletePaymentMethod( _ accessToken: String , methodId: String, success: @escaping (() -> Void) , fail: ((NSError) -> Void)? ) -> Alamofire.Request?{
//        let params = [ "accessToken": accessToken , "ID": methodId]
//        let urlStr = domain! + "/wallet/api/v1/wallet/deletePaymentMethod"
//        
//        return  request(urlStr, method: .post , parameters:  params , success: { JSON in
//            success()
//            
//            }, fail: fail)
//    }
//    
////    //MARK: - private functions
////    @discardableResult
////    internal  func request(_ url: String , method: HTTPMethod , parameters: Parameters? = nil ,encoding: ParameterEncoding = URLEncoding.default ,addedHeaders: HTTPHeaders? = nil, success: (( _ object: NSDictionary  ) -> Void)? , fail: ((NSError) -> Void)? ) -> Alamofire.Request? {
////        guard let pKey = publishableKey else{
////        return nil
////        }
////        //adding general parameters
////        var finalParams : Parameters = ["publishableKey":pKey]
////        
////        if var params = parameters{
////            if let token = token {
////                params["accessToken"] = token
////            }
////            finalParams.append(other:params)
////        }
////        var headers: HTTPHeaders = [
////            "X-Uuid": UUID,
////            "device": UIDevice.current.name,
////            "OSVersion":UIDevice.current.systemVersion
////        ]
////        if let addedHeaders = addedHeaders{
////        
////        headers.append(other: addedHeaders)
////        
////        }
////        debugPrint("params \(finalParams)" )
////        let request = Alamofire.request( url,method: method , parameters:finalParams , encoding:  encoding , headers: headers)
////            .validate(statusCode: 200..<201)
////            .validate(contentType: ["application/json"])
////            .responseString{ response in
////                printIfDebug(response)
////                
////            }.responseJSON { response in
////                
////                switch response.result {
////                case .success(let JSON):
////                                        if let success = success {
////                        success( JSON as! NSDictionary)
////                    }
////                    
////                    
////                    
////                    
////                case .failure(let error):
////                    
////                    
////                    if let fail = fail {
////                        if let data = response.data {
////                            
////                            let jsonDic = Networking.convertDataToDictionary(data)
////                            
////                            if let JSON = jsonDic {
////                                
////                                let msgKey =  JSON["message"] as? String
////                                let code = JSON["code"] as? Int
////                                if let code = code , let msgKey = msgKey {
////                                    
////                                    
////                                    //expired token handeling (login again)
////                                    if let refreshToken = self.refreshToken, code == ErrorCodes.tokenExpired{
////                                        self.login(refreshToken, success: {token in
////                                            self.request(url, method: method, parameters: finalParams, success: success, fail: fail)
////                                            return
////                                        }, fail: fail)
////                                        
////                                    }
////                                    
////                                  let msg = LocalData.manager.getString("errors" + msgKey)
////
////                                    let errorWithMessage = NSError(domain: Const.serverErrorDomain, code: code, userInfo: [NSLocalizedDescriptionKey : msg])
////                                    
////                                    fail(errorWithMessage)
////                                } else{
////                                    fail(error as NSError)
////                                }
////                            }else{
////                                fail(error as NSError)
////                            }
////                        }
////                    }
////                    
////                }
////        }
////        return request                                          
////    }
//    
//   
//   
//    
//    
//    fileprivate static func convertDataToDictionary(_ data: Data) -> [String:AnyObject]? {
//        
//        do {
//            return try JSONSerialization.jsonObject(with: data, options: []) as? [String:AnyObject]
//        } catch let error as NSError {
//            printIfDebug(error)
//        }
//        
//        return nil
//    }
//}
//