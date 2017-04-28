//
//  SecondViewController.swift
//  Automated Camera Timelapse
//
//  Created by Brian Canlas on 4/3/17.
//  Copyright © 2017 #squadgoals. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController {
    let control = Manual()
    
    // MARK: Variables

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        //control.setupManual()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: Actions
    @IBAction func up(_ sender: Any) {
        control.up()
        print("hi")
    }
    
    @IBAction func down(_ sender: Any) {
        control.down()
    }
    
    @IBAction func left(_ sender: Any) {
        control.left()
    }
    
    @IBAction func right(_ sender: Any) {
        control.right()
    }
    
    @IBAction func counter(_ sender: Any) {
        control.rotateRight()
    }
    
    @IBAction func clockwise(_ sender: Any) {
        control.rotateLeft()
    }
    
    @IBAction func shot(_ sender: Any) {
        control.shoot(time: 1/8)
    }
    
}

