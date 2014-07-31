//
//  B4SBeacon.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "B4SInteraction.h"
#import "B4SApplication.h"
#import "B4SCategory.h"
#import "B4SGroup.h"
#import "B4SShop.h"
#import "B4SZone.h"

@interface B4SBeacon : NSObject

@property (nonatomic, retain) NSString *beaconId;
@property (nonatomic, retain) NSString *innerName;

@property (nonatomic) int stuffGuardId;

@property (nonatomic) long major;
@property (nonatomic) long minor;
@property (nonatomic) int distance;
@property (nonatomic) float lastRSSI;
@property (nonatomic) int battLevel;
@property (nonatomic) int temperature;
@property (nonatomic, retain) NSString *hwVersion;
@property (nonatomic, retain) NSString *fwVersion;
@property (nonatomic, retain) NSString *model;
@property (nonatomic, retain) NSNumber *lastSeenLongitude;
@property (nonatomic, retain) NSNumber *lastSeenLatitude;

@property (nonatomic, retain) NSDate   *lastProximityAlertDate;

@property (nonatomic, retain) NSDate * lastScanDate;
@property (nonatomic) int notificationsCount;
@property (nonatomic) int notificationConsecutiveTicks;

@property (nonatomic) BOOL registered;
@property (nonatomic) BOOL userManaged; // Use to identify beacons managed by an admin user of the application
@property (nonatomic) BOOL batteryUpdateNeeded;
@property (nonatomic) BOOL batteryLevelUpdated;
@property (nonatomic) int xPos;
@property (nonatomic) int yPos;
@property (nonatomic) int zPos;

@property (nonatomic) int beaconRangeIn;
@property (nonatomic) int beaconRangeOut;

@property (nonatomic, retain) NSNumber * stuffRangeOut;

@property (nonatomic, retain) NSString * beaconPushText;
@property (nonatomic, retain) NSString * beaconPushData;
@property (nonatomic, retain) NSString * beaconClientRef;
@property (nonatomic, retain) NSString * beaconPushSoundname;
@property (nonatomic, retain) NSString * beaconName;

@property (nonatomic, retain) NSMutableSet *interactions;
@property (nonatomic, weak) B4SGroup * beaconGroup;
@property (nonatomic, weak) B4SShop * beaconShop;
@property (nonatomic, weak) B4SCategory * beaconCategory;

@property (nonatomic, weak) B4SZone * beaconZone;

- (id)initWithMajor:(long)aMajor andMinor:(long)aMinor;
- (id)initWithInnerName:(NSString *)innerName;
+ (NSString *)beaconKeyWithMajor:(long)aMajor andMinor:(long)aMinor;
+ (NSString *)beaconKey:(B4SBeacon *)aBeacon;
+ (NSString *)beaconRegionKey:(CLBeaconRegion *)aBeaconRegion;
- (NSString *)key;
- (NSString *)getSGNotif;
- (BOOL)isEqualToMajor:(NSNumber *)aMajor andMinor:(NSNumber *)aMinor;
- (BOOL)isEqualTo:(NSString *)aBeaconInnerName;
- (void)addInteraction:(B4SInteraction *)anInteraction;

- (int)beaconRangeInDistance;
- (int)beaconRangeOutDistance;

+ (B4SBeacon *)addBeacon:(B4SBeacon *)aBeacon;
+ (B4SBeacon *)getBeacon:(NSString *)aBeaconInnerName;
+ (NSArray *)beacons;
+ (void)clear;
+ (void)clearUnmanagedBeacons;
+ (int)count;
+ (int)managedBeaconsCount;
+ (void)setBeaconsAsUnmanaged;

@end
