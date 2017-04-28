//
//  SettingsTableViewController.swift
//  Automated Camera Timelapse
//
//  Created by Brian Canlas on 4/3/17.
//  Copyright © 2017 #squadgoals. All rights reserved.
//

import UIKit
import CoreBluetooth

class SettingsTableViewController: UITableViewController, BluetoothSerialDelegate {
    // MARK: Variables
    
    /// The peripherals that have been discovered (no duplicates and sorted by asc RSSI)
    var peripherals: [(peripheral: CBPeripheral, RSSI: Float)] = []
    var selectedPeripheral: CBPeripheral?
    var ready: Bool?
    
    // MARK: View Components
    @IBOutlet var tryAgainButton: UIBarButtonItem!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        ready = false
        //tryAgainButton.isEnabled = false
        
        tableView.tableFooterView = UIView()
        
        serial = BluetoothSerial(delegate: self)
//        serial.startScan()
//        Timer.scheduledTimer(timeInterval: 10, target: self, selector: #selector(SettingsTableViewController.scanTimeOut), userInfo: nil, repeats: false)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: Functions
    func scanTimeOut() {
        serial.stopScan()
        tryAgainButton.isEnabled = true
    }
    
    func connectTimeOut() {
        
        if let _ = serial.connectedPeripheral {
            return
        }
        
        if let _ = selectedPeripheral {
            serial.disconnect()
            selectedPeripheral = nil
        }
        
        ready = false
        print("Failed to connect @ connectTimeOut")
        tableView.reloadData()
    }
    
    // MARK: Actions
    @IBAction func tryAgain(_ sender: Any) {
        tryAgainButton.isEnabled = false
        serial.startScan()
        Timer.scheduledTimer(timeInterval: 10, target: self, selector: #selector(SettingsTableViewController.scanTimeOut), userInfo: nil, repeats: false)
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return peripherals.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .value1, reuseIdentifier: "cell")
        
        if ready! {
            cell.textLabel?.textColor = UIColor.green
        }
        else {
            cell.textLabel?.textColor = UIColor.red
        }
        
        cell.textLabel?.text = peripherals[(indexPath as NSIndexPath).row].peripheral.name

        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        serial.stopScan()
        selectedPeripheral = peripherals[(indexPath as NSIndexPath).row].peripheral
        serial.connectToPeripheral(selectedPeripheral!)
        
        Timer.scheduledTimer(timeInterval: 10, target: self, selector: #selector(SettingsTableViewController.connectTimeOut), userInfo: nil, repeats: false)
    }
    
    // MARK: BluetoothSerialDelegate
    
    func serialDidDiscoverPeripheral(_ peripheral: CBPeripheral, RSSI: NSNumber?) {
        // check whether it is a duplicate
        for exisiting in peripherals {
            if exisiting.peripheral.identifier == peripheral.identifier { return }
        }
        
        // add to the array, next sort & reload
        let theRSSI = RSSI?.floatValue ?? 0.0
        peripherals.append(peripheral: peripheral, RSSI: theRSSI)
        peripherals.sort { $0.RSSI < $1.RSSI }
        tableView.reloadData()
    }
    
    func serialDidFailToConnect(_ peripheral: CBPeripheral, error: NSError?) {
        
        tryAgainButton.isEnabled = true
        ready = false
        print("Failed to connect @ serialDidFailToConnect")
        tableView.reloadData()
    }
    
    func serialDidDisconnect(_ peripheral: CBPeripheral, error: NSError?) {
        
        tryAgainButton.isEnabled = true
        ready = false
        print("Failed to connect @ serialDidDisconnect")
        tableView.reloadData()
        
    }
    
    func serialIsReady(_ peripheral: CBPeripheral) {
        print("Ready")
        ready = true
        tableView.reloadData()
    }
    
    func serialDidChangeState() {
        if serial.centralManager.state != .poweredOn {
            print("Ready")
            ready = true
            tableView.reloadData()
        }
    }
}
