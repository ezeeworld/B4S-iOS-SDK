//
//  B4STag.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 19/07/2015.
//  Copyright (c) 2015 Ezeeworld. All rights reserved.
//

@import Foundation;

/**
 *  Tagging feature
 */
@interface B4STag : NSObject

/**
 *  Tag an event
 *
 *  @param anEvent  The event
 *  @param userData attached user data as a string
 */
+ (void)event:(NSString *)anEvent
     userData:(NSString *)userData;

/**
 *  Tag an event
 *
 *  @param anEvent  The event
 *  @param userDict Attached used datas a a dictionary
 */
+ (void)event:(NSString *)anEvent
     userDict:(NSDictionary *)userDict;

@end
