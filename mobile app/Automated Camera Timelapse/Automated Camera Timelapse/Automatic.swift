//
//  Automatic.swift
//  Automated Camera Timelapse
//
//  Created by Brian Canlas on 4/23/17.
//  Copyright © 2017 #squadgoals. All rights reserved.
//

import Foundation
import CoreBluetooth
import QuartzCore

class Automatic {
    // MARK: Public Variables
    public var type: String?
    public var film: String?
    public var time: Double?
    public var shots: Int?
    public var startX: Double?
    public var startY: Double?
    public var startZ: Double?
    public var endX: Double?
    public var endY: Double?
    public var endZ: Double?
    
    init() {
         serial = BluetoothSerial(delegate: self)
    }
    
    // MARK: Public Functions
    public func send() {
        let message = configure()
        
    }
    
    // MARK: Private Variables
    
    
    // MARK: Private Functions
    private func configure() -> String {
        
        return "Hello"
    }
}

extension Automatic: BluetoothSerialDelegate {
    func serialDidReceiveString(_ message: String) {
//        // add the received text to the textView, optionally with a line break at the end
//        mainTextView.text! += message
//        let pref = UserDefaults.standard.integer(forKey: ReceivedMessageOptionKey)
//        if pref == ReceivedMessageOption.newline.rawValue { mainTextView.text! += "\n" }
//        textViewScrollToBottom()
    }
    
    func serialDidDisconnect(_ peripheral: CBPeripheral, error: NSError?) {
//        reloadView()
//        dismissKeyboard()
//        let hud = MBProgressHUD.showAdded(to: view, animated: true)
//        hud?.mode = MBProgressHUDMode.text
//        hud?.labelText = "Disconnected"
//        hud?.hide(true, afterDelay: 1.0)
    }
    
    func serialDidChangeState() {
//        reloadView()
//        if serial.centralManager.state != .poweredOn {
//            dismissKeyboard()
//            let hud = MBProgressHUD.showAdded(to: view, animated: true)
//            hud?.mode = MBProgressHUDMode.text
//            hud?.labelText = "Bluetooth turned off"
//            hud?.hide(true, afterDelay: 1.0)
//        }
    }
}
