//
//  B4SBeacon.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>

@class B4SGroup;
@class B4SCategory;
@class B4SShop;

@interface B4SBeacon : NSObject
/**
 Name of the iBeacon : B4S:xxxx:xxxx
 */
@property (nonatomic, retain) NSString *innerName;
/**
 iBeacon major value
 */
@property (nonatomic) long major;
/**
 iBeacon minor value
 */
@property (nonatomic) long minor;
/**
 Distance from the iBeacon.
 */
@property (nonatomic) int distance;
/**
 Last rssi value of the iBeacon.
 */
@property (nonatomic) float lastRSSI;
/**
 Last battery level reported for the iBeacon.
 */
@property (nonatomic) int battLevel;
/**
 Last temperature reported for the iBeacon.
 */
@property (nonatomic) int temperature;
@property (nonatomic, retain) NSString *hwVersion;
@property (nonatomic, retain) NSString *fwVersion;
@property (nonatomic, retain) NSString *model;
/**
 Last longitude the iBeacon was seen.
 */
@property (nonatomic, retain) NSNumber *lastSeenLongitude;
/**
 Last latitude the iBeacon was seen.
 */
@property (nonatomic, retain) NSNumber *lastSeenLatitude;
/**
 Last time the iBeacon was seen by a customer application
 */
@property (nonatomic, retain) NSDate * lastScanDate;
/**
 Map X position of the iBeacon
 */
@property (nonatomic) int xPos;
/**
 Map Y position of the iBeacon
 */
@property (nonatomic) int yPos;
/**
 Map Z position of the iBeacon
 */
@property (nonatomic) int zPos;

@property (nonatomic) int beaconRangeIn;
@property (nonatomic) int beaconRangeOut;

/**
 iBeacon notification text
 */
@property (nonatomic, retain) NSString * beaconPushText;
/**
 iBeacon notification data
 */
@property (nonatomic, retain) NSString * beaconPushData;
/**
 iBeacon customer reference
 */
@property (nonatomic, retain) NSString * beaconClientRef;
/**
 iBeacon given name
 */
@property (nonatomic, retain) NSString * beaconName;

/**
 Interactions matching with the iBeacon.
 */
@property (nonatomic, retain) NSMutableSet *interactions;
/**
 Group the iBeacon belongs to.
 */
@property (nonatomic, weak) B4SGroup * beaconGroup;
/**
 Shop the iBeacon belongs to.
 */
@property (nonatomic, weak) B4SShop * beaconShop;
/**
 Category the iBeacon is attached to.
 */
@property (nonatomic, weak) B4SCategory * beaconCategory;

- (int)beaconRangeInDistance;

/**
 List of iBeacons downloaded from the backend
 */
+ (NSArray *)beacons;
/**
 Number of iBeacons downloaded from the backend
 */
+ (int)count;

@end
