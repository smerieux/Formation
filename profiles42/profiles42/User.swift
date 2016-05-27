//
//  User.swift
//  profiles42
//
//  Created by Sylvain MERIEUX on 1/18/16.
//  Copyright © 2016 smerieux. All rights reserved.
//

import UIKit
import JSONJoy

struct Project {
    
    var nameProject: String?
    var markProject: Float?
    
    init() {
        
    }
    
    init(_ decoder: JSONDecoder) {
        nameProject = decoder["slug"].string
        markProject = decoder["final_mark"].float
    }
}

struct Skill {
    
    var nameSkill: String?
    var levelSkill: Float?
    
    init() {
        
    }
    
    init(_ decoder: JSONDecoder) {
        nameSkill = decoder["name"].string
        levelSkill = decoder["level"].float
    }
}

class User: JSONJoy{
    
    var displayName: String?
    var login: String?
    var photo: String?
    var email: String?
    var mobile: String?
    var location: String?
    var userError: String?

    var projects: Array<Project>?
    var skills: Array<Skill>?
   
    var level: Float?
    var grade: String?
    
    init() {
        
    }
    
    required init(_ decoder: JSONDecoder) {
        displayName = decoder["displayname"].string
        login = decoder["login"].string
        photo = decoder["image_url"].string
        email = decoder["email"].string
        mobile = decoder["phone"].string
        location = decoder["location"].string
        userError = decoder["error"].string
        if let cur = decoder["cursus"].array {
            for decoder in cur {
                level = decoder["level"].float
                grade = decoder["grade"].string
                
                let pro = decoder["projects"].array
                    projects = Array<Project>()
                    for decoder in pro! {
                        projects!.append(Project(decoder))
                }
                let ski = decoder["skills"].array
                    skills = Array<Skill>()
                    for decoder in ski! {
                        skills!.append(Skill(decoder))
                }
            }
        }
    }
}

