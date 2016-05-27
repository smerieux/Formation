//
//  Token.swift
//  profiles42
//
//  Created by Sylvain MERIEUX on 1/13/16.
//  Copyright © 2016 smerieux. All rights reserved.
//

import UIKit
import JSONJoy

class Token {

    var accessToken: String?
    var tokenType: String?
    var expiresIn: Int?
    var login: Int!
    var scope: String?
    var createdAt: String?
    var error: String?
    
    init() {
        
    }
    
    init(_ decoder: JSONDecoder) {
        accessToken = decoder["access_token"].string
        tokenType = decoder["token_type"].string
        expiresIn = decoder["expires_in"].integer
        login = decoder["id"].integer
        scope = decoder["scope"].string
        createdAt = decoder["created_at"].string
        error = decoder["error"].string
    }
}
