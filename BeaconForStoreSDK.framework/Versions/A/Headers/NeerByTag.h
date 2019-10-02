//
//  NeerByTag.h
//  BeaconForStoreSDK
//
//  Created by Christophe Janot on 25/09/2019.
//  Copyright © 2019 Ezeeworld. All rights reserved.
//

@interface NeerByTag : NSObject

@property (nonatomic) int timestamp;
@property (nonatomic, retain) CLLocation *lastLocation;
@property (nonatomic) float averageSpeed;
@property (nonatomic) int   speedIndex;
@property (nonatomic) int   precision;

@property (nonatomic, retain) NSString *appVersion;
@property (nonatomic, retain) NSString *sdkVersion;
@property (nonatomic, retain) NSString *osVersion;

@property (nonatomic, retain) NSString *type;
@property (nonatomic, retain) NSString *data;

+ (void)newEvent:(NSString *)aTagType
            data:(NSDictionary *)aDataDict;

@end
