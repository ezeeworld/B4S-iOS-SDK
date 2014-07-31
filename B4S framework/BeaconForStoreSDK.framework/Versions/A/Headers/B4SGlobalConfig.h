//
//  BeaconForStoreSDK.h
//  BeaconForStoreSDK 
//
//  Created by Christophe JANOT on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import "B4S_AFHTTPClient.h"
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "B4SShop.h"
#import "B4SMotionDetector.h"

@interface B4SGlobalConfig : B4S_AFHTTPClient

@property (nonatomic, retain) NSString *appId;
@property (nonatomic, retain) NSString *beaconsUuid;
@property (nonatomic, retain) NSString *clientId;
@property (nonatomic, retain) NSString *baseUrl;
@property (nonatomic, retain) NSString *udid;

@property (nonatomic) BOOL wifiOnlyUpload;
@property (nonatomic) float defaultTxPower;
@property (nonatomic) float txPowerBatteryCompensation;
@property (nonatomic) float txPowerTemperatureCompensation;
@property (nonatomic, retain) CLLocation *currentGPSLocation;
@property (nonatomic, retain) NSNumber *maxSessionStorageDuration;
@property (nonatomic, retain) NSNumber *sessionTimeout;
@property (nonatomic, retain) NSNumber *backgroundTimeout; // In seconds
@property (nonatomic, retain) NSNumber *reloadInterval;
@property (nonatomic, retain) NSNumber *geofencingRadius;
@property (nonatomic, retain) NSNumber *customerTrackingSyncRate;
@property (nonatomic, retain) NSNumber *beaconsCacheValidity; // In minutes
@property (nonatomic, retain) NSNumber *scanSampleRate; // Sample rate used to send passive scan record to the back
@property (nonatomic, retain) NSNumber *radius; // Radius of beacons to be downloaded
@property (nonatomic) float mapHeading;

- (id)initWithBaseURL:(NSString *)anUrl applicationId:(NSString *)anAppId adminMode:(Boolean)isAdminMode;
+ (void)requestSetup:(NSMutableURLRequest *)request;
- (Boolean)areParametersUptodate;
- (Boolean)isMapUptodate;
- (void)getApplicationData:(void (^)(NSError *error))completion;
- (Boolean)configurationLoaded;
- (void)clearCache;

- (void)queryAdminSetup;

- (void)getNearestShopAtLongitude:(float)aLongitude andLatitude:(float)aLatitude completion:(void (^)(B4SShop *shop))completion;
- (void)shopZonesList:(void (^)(Boolean error))completion;

- (B4SMovement)movement;

+ (B4SGlobalConfig*) sharedInstance;
+ (B4SGlobalConfig*) setupSharedInstanceWithBaseURL:(NSString *)anUrl
                                      applicationId:(NSString *)anAppId
                                          adminMode:(Boolean)isAdminMode;

@end
