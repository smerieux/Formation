//
//  InterfaceController.swift
//  profiles42
//
//  Created by Sylvain MERIEUX on 1/12/16.
//  Copyright © 2016 smerieux. All rights reserved.
//

import UIKit
import JSONJoy
import SwiftHTTP

class InterfaceController: UIViewController , UITableViewDataSource, UITableViewDelegate{
    
    var userInfo:User!
    var userToken:String!
    
    @IBOutlet weak var loginPassedData: UILabel!
    @IBOutlet weak var labelPassedData: UILabel!
    @IBOutlet weak var emailPassedData: UILabel!
    @IBOutlet weak var photo: UIImageView!
    @IBOutlet weak var idView: UIView!
    @IBOutlet weak var homeButton: UIButton!
    @IBOutlet weak var mobilePassedData: UILabel!
    @IBOutlet weak var locationPassedData: UILabel!
    @IBOutlet weak var gradePassedData: UILabel!
    @IBOutlet weak var levelPassedData: UILabel!
    @IBOutlet weak var skillPassedData: UILabel!
    @IBOutlet weak var emptyBarSkill: UIView!
    @IBOutlet weak var levelBar: UIProgressView!
    
    @IBOutlet weak var projectTableView: UITableView!    
    @IBOutlet weak var skillTableView: UITableView!
    
    private func displayPhoto() {
        if let url  = NSURL(string: userInfo.photo!),
            data = NSData(contentsOfURL: url)
        {
            photo.image = UIImage(data: data)
        }
    }
    
    private func updateUI() {
        self.view.backgroundColor = UIColor(patternImage: UIImage(named: "background_login.png")!)
        self.idView.layer.backgroundColor = UIColor(red: 0.0, green:0.0, blue: 0.0, alpha: 0.4).CGColor
        self.idView.layer.cornerRadius = 2.0
        self.idView.layer.borderWidth = 2.0
        self.idView.layer.borderColor = UIColor(red: 0.0, green:174.0, blue: 175.0, alpha: 0.7).CGColor
        self.emptyBarSkill.layer.cornerRadius = 2.0
        self.projectTableView.layer.cornerRadius = 2.0
        self.skillTableView.layer.cornerRadius = 2.0

    }
    
    private func displayPassedData() {
        labelPassedData.text! = "\(userInfo.displayName!)"
        loginPassedData.text! = "login: \(userInfo.login!)"
        emailPassedData.text! = "\(userInfo.email!)"
        mobilePassedData.text! = "\(userInfo.mobile!)"
        if ((userInfo.location) == nil) {
            locationPassedData.text! = "-not logged in-"
        } else {
            locationPassedData.text! = "location: \(userInfo.location!)"
        }
        gradePassedData.text! = "\(userInfo.grade!)"
       
        let split = String(userInfo.level!).componentsSeparatedByString(".")
        let toFloat = (split[1] as NSString).floatValue
        levelBar.progress = toFloat/100
        levelPassedData.text = "Lvl \(split[0]) - \(split[1])%"
        
        let mySkills = self.userInfo!.skills![0]
        let nameSkill = mySkills.nameSkill!
        let levelSkill = mySkills.levelSkill!
        
        skillPassedData.text! = "-Best skill- \(nameSkill): " + "\(levelSkill)"
        
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        updateUI()
        displayPhoto()
        displayPassedData()
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "DisplayHome" {
            let svc = segue.destinationViewController as! ViewController;
            
            svc.copyToken = self.userToken
        }
    }
    
    // MARK: - Table view data source
    func numberOfSectionsInTableView(tableview: UITableView) -> Int {
        return 1
    }
    
    func tableView(tableview: UITableView, numberOfRowsInSection section: Int) -> Int {
        if tableview == projectTableView {
            return (userInfo.projects?.count)!
        } else {
            return (userInfo.skills?.count)!
        }
    }

    
    func tableView(tableview: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
    
    // Configure the cell...
        if tableview == projectTableView {
            // Table view cells are reused and should be dequeued using a cell identifier.
            let cellIdentifier = "ProjectCell"
            let cell = projectTableView.dequeueReusableCellWithIdentifier(cellIdentifier, forIndexPath: indexPath) as! MyTableViewCell
            
            let projects = userInfo.projects![indexPath.row]
            
            cell.nameProject?.font = UIFont(name: "avenir", size: 12)
            cell.markProject?.font = UIFont(name: "avenir", size: 12)
            if projects.markProject == nil {
                cell.nameProject?.text = "\(projects.nameProject!)"
                cell.nameProject?.textColor = UIColor.blackColor()
                cell.markProject?.textColor = UIColor(red: 5, green: 5, blue: 0, alpha: 1.0)
                cell.markProject?.text = "En cours"
            } else if projects.markProject == 0 {
                cell.nameProject?.text = "\(projects.nameProject!)"
                cell.nameProject?.textColor = UIColor.blackColor()
                cell.markProject?.textColor = UIColor.redColor()
                cell.markProject?.text = "Failed(\(projects.markProject!)%)"
            } else {
                cell.nameProject?.text = "\(projects.nameProject!)"
                cell.nameProject?.textColor = UIColor.blackColor()
                cell.markProject?.textColor = UIColor.blackColor()
                cell.markProject?.text = "\(projects.markProject!)%"
            }
            return cell

        } else {
            let cellIdentifier = "SkillCell"
            let cell = skillTableView.dequeueReusableCellWithIdentifier(cellIdentifier, forIndexPath: indexPath) as! MyTableViewCell
            
            let skills = userInfo.skills![indexPath.row]
            
            cell.nameSkill?.font = UIFont(name: "avenir", size: 12)
            cell.nameSkill.text = "\(skills.nameSkill!)"
            
            let split = String(skills.levelSkill!).componentsSeparatedByString(".")
            let toFloat = (split[1] as NSString).floatValue
            cell.progressSkill.progress = toFloat/100
            
            cell.labelSkill.text = "Lvl \(split[0])-\(split[1])%"
            
            return cell
        }
    }
}
