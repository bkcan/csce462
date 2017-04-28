//
//  EndViewController.swift
//  Automated Camera Timelapse
//
//  Created by Brian Canlas on 4/23/17.
//  Copyright © 2017 #squadgoals. All rights reserved.
//

import UIKit

class EndViewController: UIViewController {
    // MARK: Variables
    var slider: MTCircularSlider?
    
    // MARK: View Components
    @IBOutlet var endXSlider: UISlider!
    @IBOutlet var endYSlider: UIView!
    @IBOutlet var endZSlider: UISlider! {
        didSet{
            endZSlider.transform = CGAffineTransform(rotationAngle: -CGFloat.pi)
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        slider = MTCircularSlider(frame: endYSlider.bounds)
        slider?.addTarget(self, action: #selector(valueChange(_:)), for: .valueChanged)
        endYSlider.addSubview(slider!)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: Actions
    
    func valueChange(_ sender: Any) {
        
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
