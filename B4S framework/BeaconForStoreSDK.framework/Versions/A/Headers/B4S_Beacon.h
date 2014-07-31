//
//  EZBBeacon.h
//  EZBeacon
//
//  Created by Christophe JANOT on 12/03/2014.
//  Copyright (c) 2014 Christophe JANOT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "B4SMotionDetector.h"
#import "B4SBeacon.h"
#import "B4SRSSI.h"
#import "B4SGroup.h"
#import "B4SShop.h"
#import "B4SInteraction.h"
#import "B4SGlobalConfig.h"

@interface B4S_Beacon : B4SBeacon

@property (nonatomic, retain) NSString * categoryId;
@property (nonatomic, retain) NSDate * lastScanDate;
@property (nonatomic) int notificationsCount;
@property (nonatomic) int notificationConsecutiveTicks;
@property (nonatomic, retain) NSString * beaconId;
@property (nonatomic, retain) NSString * beaconClientRef;
@property (nonatomic, retain) NSString * shopId;
@property (nonatomic, retain) NSString * groupId;
@property (nonatomic, retain) NSMutableSet *interactions;

@property (nonatomic) BOOL registered;

@property (nonatomic) int battLevel;
@property (nonatomic) int temperature;

@property (nonatomic) int   activeChannel;
@property (nonatomic) float lastRSSI37;
@property (nonatomic) float lastRSSI38;
@property (nonatomic) float lastRSSI39;

@property (nonatomic, retain) B4SRSSI *rssiAC;
@property (nonatomic, retain) B4SRSSI *rssi37;
@property (nonatomic, retain) B4SRSSI *rssi38;
@property (nonatomic, retain) B4SRSSI *rssi39;

- (id)initWithMajor:(long)aMajor andMinor:(long)aMinor;
- (void)addInteraction:(B4SInteraction *)interaction;
- (void)clear;
- (void)clearRssiValue;
+ (void)setup;
+ (void)clearRssiValues;
+ (NSMutableSet *)beacons;
+ (B4S_Beacon *)isMultipleBeacons;
+ (BOOL)isB4SDevice:(NSString *)aName;
+ (B4S_Beacon *)addBeaconWithMajor:(long)aMajor andMinor:(long)aMinor;
+ (B4S_Beacon *)addBeaconWithBeaconName:(NSString *)aName;
+ (B4S_Beacon *)getBeacon:(NSString *)key;
+ (NSArray *)getSortedBeaconsList;
+ (B4S_Beacon *)getNearestBeacon;
+ (B4S_Beacon *)getImmediateBeacon;

- (float)recordRssi:(float)rssi onChannel:(int)aChannel movement:(B4SMovement)aMovement;
- (float)smoothRssi:(float)rssi onChannel:(int)aChannel;
- (float)distance:(B4SGlobalConfig *)config;
- (float)computeDistance;

- (void)saveBeacon:(B4S_Beacon *)aBeacon
        completion:(void (^)(Boolean success))completion;
- (void)removeBeacon:(B4S_Beacon *)aBeacon
          completion:(void (^)(Boolean success))completion;
+ (void)removeBeaconById:(NSString *)aBeaconId
              completion:(void (^)(Boolean success))completion;

@end
