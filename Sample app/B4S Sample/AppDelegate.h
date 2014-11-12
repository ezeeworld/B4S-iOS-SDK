//
//  AppDelegate.h
//  B4S Sample
//
//  Created by Stéphanie Spenlé on 30/07/2014.
//  Copyright (c) 2014 ezeeworld. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BeaconForStoreSDK/BeaconForStoreSDK.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate,B4SDelegate,UIAlertViewDelegate,UIImagePickerControllerDelegate>

@property (strong, nonatomic) UIWindow *window;

@end
