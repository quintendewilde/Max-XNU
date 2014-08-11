//
//  main.m
//  Swatch-GNU
//
//  Created by Eli Hutton on 8/11/14.
//  Copyright (c) 2014 hutdev. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AppleScriptObjC/AppleScriptObjC.h>

int main(int argc, const char * argv[]) {
      [[NSBundle mainBundle] loadAppleScriptObjectiveCScripts];
      return NSApplicationMain(argc, argv);
}
