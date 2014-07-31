//
//  Beacon.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 10/06/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Beacon : NSManagedObject

@property (nonatomic, retain) NSString * innerName;
@property (nonatomic, retain) NSString * model;
@property (nonatomic, retain) NSString * hwVersion;
@property (nonatomic, retain) NSString * fwVersion;
@property (nonatomic, retain) NSNumber * batteryLevel;
@property (nonatomic, retain) NSNumber * tempLevel;
@property (nonatomic, retain) NSNumber * latitude;
@property (nonatomic, retain) NSNumber * longitude;
@property (nonatomic, retain) NSDate * date;

@end
