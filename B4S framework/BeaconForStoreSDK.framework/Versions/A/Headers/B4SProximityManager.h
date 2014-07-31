//
//  ProximityManager.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "B4SBeacon.h"

static float kB4SGuardDistance = 3;
static float kB4SGuardResetDistance = 0.3f;
static int kB4SNotifInterval = 30;

@interface B4SProximityManager : NSObject

- (id)init:(NSSet *)monitoredRegions;
+ (B4SBeacon *)addBeacon:(B4SBeacon *)aBeacon;
+ (B4SBeacon *)removeBeacon:(B4SBeacon *)aBeacon;
+ (NSArray *)beaconsList;
+ (int)count;
+ (B4SBeacon *)getBeaconInnerName:(NSString *)innerName;
+ (B4SBeacon *)getBeaconForMajor:(int)major minor:(int)minor;
+ (B4SBeacon *)isBeaconManaged:(NSString *)innerName;
+ (NSArray *)rangedBeacons;
+ (B4SBeacon *)beaconAt:(int)row;

@end
