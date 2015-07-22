//
//  B4STag.h
//  BeaconForStoreSDK
//
//  Created by Christophe Janot on 19/07/2015.
//  Copyright (c) 2015 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface B4STag : NSObject

+ (void)event:(NSString *)anEvent
     userData:(NSString *)userData;
+ (void)event:(NSString *)anEvent
     userDict:(NSDictionary *)userDict;

@end
