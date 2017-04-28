//
//  StartViewController.swift
//  Automated Camera Timelapse
//
//  Created by Brian Canlas on 4/23/17.
//  Copyright © 2017 #squadgoals. All rights reserved.
//

import UIKit

class StartViewController: UIViewController {
    // MARK: Variables
    var slider: MTCircularSlider?
    
    @IBOutlet var xSlider: UISlider!
    @IBOutlet var ySlider: UIView!
    @IBOutlet var zSlider: UISlider! {
        didSet{
            zSlider.transform = CGAffineTransform(rotationAngle: CGFloat.pi/2)
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        slider = MTCircularSlider(frame: ySlider.bounds)
        slider?.addTarget(self, action: #selector(valueChange(_:)), for: .valueChanged)
        ySlider.addSubview(slider!)
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
