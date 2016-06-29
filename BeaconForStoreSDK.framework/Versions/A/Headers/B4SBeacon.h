//
//  B4SBeacon.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;

@class B4SGroup;
@class B4SCategory;
@class B4SShop;
@class B4SInteraction;
@class CLLocation;

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
@property (nonatomic) BOOL runStatus;
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
@property (nonatomic, retain) NSDate *lastScanDate;
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


/**
 iBeacon notification text
 */
@property (nonatomic, retain) NSString *pushText;
/**
 iBeacon notification data
 */
@property (nonatomic, retain) NSString *pushData;
/**
 iBeacon customer reference
 */
@property (nonatomic, retain) NSString *clientRef;
/**
 iBeacon given name
 */
@property (nonatomic, retain) NSString *name;

/**
 Interactions matching with the iBeacon.
 */
@property (nonatomic, retain) NSMutableSet<B4SInteraction *> *interactions;
/**
 Group the iBeacon belongs to.
 */
@property (nonatomic, weak) B4SGroup *beaconGroup;
/**
 Shop the iBeacon belongs to.
 */
@property (readonly) B4SShop *beaconShop;
/**
 Category the iBeacon is attached to.
 */
@property (nonatomic, weak) B4SCategory *beaconCategory;

/**
 Virtual beacon coordinates.
 */
@property (nonatomic, retain) CLLocation *location;
/**
 Virtual beacon radius.
 */
@property (nonatomic) float radius;


/**
 List of iBeacons downloaded from the backend
 */
+ (NSArray<B4SBeacon *> *)beacons;
/**
 Number of iBeacons downloaded from the backend
 */
+ (int)count;

/**
 *  Details on where is located
 */
@property(readonly) NSString    *beaconDescription;
@end
