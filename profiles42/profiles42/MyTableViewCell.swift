//
//  MyTableViewCell.swift
//  profiles42
//
//  Created by Sylvain MERIEUX on 1/27/16.
//  Copyright © 2016 smerieux. All rights reserved.
//

import UIKit

class MyTableViewCell: UITableViewCell {

    
    @IBOutlet weak var nameSkill: UILabel!    
    @IBOutlet weak var progressSkill: UIProgressView!
    @IBOutlet weak var labelSkill: UILabel!
    
    @IBOutlet weak var nameProject: UILabel!
    @IBOutlet weak var markProject: UILabel!
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
