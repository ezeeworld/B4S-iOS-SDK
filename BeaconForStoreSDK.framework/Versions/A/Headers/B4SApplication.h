//
//  B4SApplication.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 21/07/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;

@interface B4SApplication : NSObject

/**
 ApplicationId which had to be used to instantiate B4SSingleton
 */
@property (nonatomic, retain) NSString *applicationId;
/**
 Given name of the iBeacon
 */
@property (nonatomic, retain) NSString *name;
/**
 iBeacon additional data
 */
@property (nonatomic, retain) NSString *appDescription;

/**
 Returns the application name associated to the given applicationId.
 */
+ (NSString *)getApplicationName:(NSString *)anApplicationId;
/**
 Returns the B4SApplication object  associated to the given applicationId.
 */
+ (B4SApplication *)getApplication:(NSString *)anApplicationId;
/**
 Returns an array of the applications previously loaded with the B4SSingleton fullAppsList method.
 */
+ (NSArray<B4SApplication *> *)applications;

/**
 Returns applications count.
 */
+ (int)count;

@end
