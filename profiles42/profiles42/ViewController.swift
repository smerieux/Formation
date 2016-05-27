//
//  ViewController.swift
//  profiles42
//
//  Created by Sylvain MERIEUX on 1/12/16.
//  Copyright © 2016 smerieux. All rights reserved.
//

import UIKit
import JSONJoy
import SwiftHTTP

class ViewController: UIViewController {
    
    var placeholder = NSAttributedString(string: "Login", attributes: [NSForegroundColorAttributeName : UIColor.grayColor()])
    var UID = "db1a11caff474f17aa40b17ffb2050207d2352313d08cfcdca62eda126b8b86a"
    var SECRET = "f1478af326ffa96fd2443d0102de4d8cfeb4b8eff0ce9f9dd611be5d8b119a30"
    var copyToken :String?
    var token :Token?
    var user :User?
    var radius :CGFloat = 4.5
    var responseError = false
    var requestError = false
    
    @IBOutlet weak var connexionButton: UIButton!
    @IBOutlet weak var loginField: UITextField!

    private func updateUI() {
        self.view.backgroundColor = UIColor(patternImage: UIImage(named: "background_login.png")!)
        self.connexionButton.layer.cornerRadius = radius
        self.loginField.attributedPlaceholder = placeholder
        self.loginField.layer.cornerRadius = radius
        self.loginField.layer.borderWidth = 2.0
        self.loginField.layer.borderColor = UIColor(red: 0.0, green:174.0, blue: 175.0, alpha: 0.7).CGColor
    }
    
    private func getToken() -> Void{
        let params = ["grant_type": "client_credentials", "client_id": "\(UID)", "client_secret": "\(SECRET)"]
        
        do {
            let opt = try HTTP.POST("https://api.intra.42.fr/oauth/token", parameters: params)
            opt.start { response in
                if let err = response.error {
                    print("error: \(err.localizedDescription)")
                    return
                }
                self.token = Token(JSONDecoder(response.data))
                if let err = self.token!.error {
                    print("got an error: \(err)")
                }
                if let status = self.token!.accessToken {
                print("completed: \(status)")
                }
                // print("opt finished: \(response.description)")
            }
        }
        catch let error {
            print("got an error creating the request: \(error)")
        }
    }
    
    @IBAction func loginAppend(sender: UITextField) {
       loginField.layer.borderColor = UIColor(red: 0.0, green:184.0, blue: 185.0, alpha: 0.9).CGColor
    }
    
    @IBAction func sendRequest(sender: UIButton) {
        
        var login :String
        login = loginField.text!
        self.responseError = false
        self.requestError = false

      do {
        let params :Dictionary<String, String>
        
        if ((copyToken?.isEmpty) == nil) {
            params = ["access_token": "\(token!.accessToken!)"]
        } else {
            params = ["access_token": "\(copyToken!)"]
        }

            let opt = try HTTP.GET("https://api.intra.42.fr/v2/users/\(login)", parameters: params)
            opt.start { response in

                if let error = response.error {
                    print("got an error: \(error)")
                    self.responseError = true
                    dispatch_async(dispatch_get_main_queue()){
                        self.shouldPerformSegueWithIdentifier("DisplayUserInfo", sender: self.connexionButton)
                    }
                    return
                }
                self.user = User(JSONDecoder(response.data))
             //   print("opt finished: \(response.description)")
                let loginSuccessful: Bool = true

                if loginSuccessful && !self.responseError {
                    dispatch_async(dispatch_get_main_queue()) { () -> Void in
                        self.performSegueWithIdentifier("DisplayUserInfo", sender: self.connexionButton)
                        }
                }
            }
        } catch let error {
            print("error in request: \(error)")
            self.requestError = true
            dispatch_async(dispatch_get_main_queue()){
                self.shouldPerformSegueWithIdentifier("DisplayUserInfo", sender: self.connexionButton)
            }
        }
    }

    internal func displayToken() -> Void {
        print("token: \(self.token?.accessToken)")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        if ((self.copyToken) == nil){
            getToken()
            print("A new token has been created for 7200 secondes left")
        } else {
            print("A token already exists")
        }
        updateUI()
    }

    override func shouldPerformSegueWithIdentifier(identifier: String, sender: AnyObject!) -> Bool {
        let login = loginField.text!
        if identifier == "DisplayUserInfo" {
            
            if login.isEmpty {
                print("empty login field")
                let alertController = UIAlertController(title: "No text", message: "Please Enter Text In The Box", preferredStyle: .Alert)
                let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
                
                alertController.addAction(defaultAction)
                presentViewController(alertController, animated: true, completion: nil)
                return false
            }
            else if responseError {
                let alertController = UIAlertController(title: "Wrong Id", message: "Please Enter An Existing Login", preferredStyle: .Alert)
                let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
                
                alertController.addAction(defaultAction)
                presentViewController(alertController, animated: true, completion: nil)
                return false
            }
            else if requestError{
                let alertController = UIAlertController(title: "Invalid Request", message: "Please Remove Any White Space", preferredStyle: .Alert)
                let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
                
                alertController.addAction(defaultAction)
                presentViewController(alertController, animated: true, completion: nil)
                return false
            }
        }
        // by default, transition
        return true
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "DisplayUserInfo" {
            let svc = segue.destinationViewController as! InterfaceController;
            
            svc.userInfo = self.user!
            if ((copyToken?.isEmpty) == nil) {
                svc.userToken = self.token?.accessToken!
            } else {
                svc.userToken = self.copyToken!
            }
        }
    }
}