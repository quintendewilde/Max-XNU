//
//  ActionViewController.swift
//  Neural Interface Sources
//
//  Created by Eli Hutton on 8/11/14.
//  Copyright (c) 2014 SwatchXNU. All rights reserved.
//

import Cocoa

class ActionViewController: NSViewController {

    @IBOutlet var myTextView: NSTextView!
    
    override var nibName: String {
        return "ActionViewController"
    }

    override func loadView() {
        super.loadView()
    
        // Insert code here to customize the view
        NSLog("Input Items = %@", self.extensionContext.inputItems)
    
        let sharedItem = self.extensionContext.inputItems[0] as NSExtensionItem
        let text = sharedItem.attributedContentText.string
    
        if !text.isEmpty {
            self.myTextView.string = text
        }
    }

    @IBAction func send(sender: AnyObject?) {
        let outputItem = NSExtensionItem()
        outputItem.attributedContentText = self.myTextView.attributedString()
    
        let outputItems = [outputItem]
        self.extensionContext.completeRequestReturningItems(outputItems, completionHandler: nil)
    }

    @IBAction func cancel(sender: AnyObject?) {
        let cancelError = NSError.errorWithDomain(NSCocoaErrorDomain, code: NSUserCancelledError, userInfo: nil)
        self.extensionContext.cancelRequestWithError(cancelError)
    }

}
