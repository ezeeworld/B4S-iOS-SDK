//
//  B4SSingleton.h
//  BeaconForStoreSDK
//
//  Created by Christophe JANOT on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#import "B4S_AFHTTPClient.h"
#import "B4SBeacon.h"
#import "B4SSession.h"
#import "B4SCustomerData.h"
#import "B4SUserAccount.h"
#import <UIKit/UIKit.h>

static NSString *const kB4SBeaconNotificationName = @"B4SBeaconNotification";
static NSString *const kB4SBeaconOutOfRangeNotificationName = @"B4SBeaconOutOfRangeNotification";
static NSString *const kB4SConfigurationUpdate = @"B4SBeaconConfigUpdate";
static NSString *const kB4SZonesUpdate = @"B4SZonesConfigUpdate";

enum B4SBeaconStatus {
    kB4SDETECT_UNDEFINED,
    kB4SDETECT_NO_BEACON,
    kB4SDETECT_MULTIPLE_BEACONS,
    kB4SDETECT_QUERY_BEACON,
    kB4SDETECT_NEW_BEACON,
    kB4SDETECT_REGISTERED,
    kB4SDETECT_REG_ERROR,
    kB4SDETECT_EXISTING,
    kB4SDETECT_SRV_ERROR,
    kB4SDETECT_UNAUTHORIZED
};
typedef enum B4SBeaconStatus B4SBeaconStatus;

enum B4SConfigUpdateCause {
    kB4SCONFIGUPDT_SDKLOOP,
    kB4SCONFIGUPDT_MOVE,
    kB4SCONFIGUPDT_BEACONREG,
    kB4SCONFIGUPDT_IBSDKLOOP,
    kB4SCONFIGUPDT_REGIONIN,
    kB4SCONFIGUPDT_REGIONOUT,
    kB4SCONFIGUPDT_APPSTART

};
typedef enum B4SConfigUpdateCause B4SConfigUpdateCause;

@class B4SSingleton;

@protocol B4SDelegate <NSObject>

@optional
- (void)customizeNotificationText:(NSString *)aText
                          andData:(NSString *)aData
                      andUserInfo:(NSMutableDictionary *)userInfos
                       completion:(void (^)(NSString *pushText, NSString *pushData, NSMutableDictionary *userInfos))completion;
- (void)beaconStatusChanged:(int)status;
- (void)configurationUpdated;
- (void)zonesUpdated;
- (void)beaconInfos:(B4SBeacon *)beacon;
- (void)login:(BOOL)loggedIn error:(BOOL)error badAccess:(BOOL)badAccess;
- (void)userLoggedIn:(NSString *)clientId setupAccess:(Boolean)hasSetup metricsAccess:(Boolean)hasMetrics error:(BOOL)error badAccess:(BOOL)badAccess;
- (void)logout;
- (void)beaconsInRange:(NSArray *)beacons nearest:(B4SBeacon *)aBeacon;
- (void)customerPosition:(int)x y:(int)y;
@end

@interface B4SSingleton : B4S_AFHTTPClient

@property int                 requestTimeout; // AFRequest timeout
@property (nonatomic) Boolean manageStatEvents;
@property (nonatomic, retain) NSString *appId;
@property (nonatomic, retain) NSString *clientId;
@property (nonatomic, retain) B4SShop *currentShop;
@property (nonatomic, retain) NSString *userId;
@property (nonatomic, retain) NSString *authToken;
@property (nonatomic, weak)   id<B4SDelegate> delegate;
@property (nonatomic, retain) NSString *notificationSoundname;

@property (nonatomic) Boolean adminMode;

- (id)initWithAppId:(NSString *)anAppId adminMode:(Boolean)isAdminMode;
- (B4SBeacon *)getCurrentBeacon;
- (void)monitorBeacons:(BOOL)enabled;
- (NSSet *)monitoredRegions;
- (void)configRefresh:(B4SConfigUpdateCause)aCause;
- (void)monitorStuffGuard;
- (void)monitorClosestStuffGuardBeacons;
- (void)waitForClosestBeacon;
- (void)startStandAloneMode;
- (void)startRangingBeacon;
- (void)stopRangingBeacon;
- (void)rescanBeacons;
- (B4SBeacon *)queryNearestBeaconStatus;
- (void)didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;

- (Boolean)isAuthentified;

- (NSDictionary *)getLastNotificationData;

- (void)setBackgroundMode;
- (void)setForegroundMode;

- (void)requestSetup:(NSMutableURLRequest *)request;
- (void)test;
- (void)startTimer;
- (void)stopTimer;

- (void)lostPassword:(NSString *)anEmail completion:(void (^)(Boolean success, Boolean unknownEmail))completion;
- (void)login:(NSString *)anEmail password:(NSString *)aPassword;
- (void)saveApplication:(B4SApplication *)anApplication
             completion:(void (^)(Boolean success))completion;
- (void)deleteAplication:(B4SApplication *)application
              completion:(void (^)(Boolean success))completion;
- (void)saveGroup:(B4SGroup *)group
       completion:(void (^)(Boolean success))completion;
- (void)deleteGroup:(B4SGroup *)group
         completion:(void (^)(Boolean success))completion;
- (void)saveShop:(B4SShop *)shop
      completion:(void (^)(Boolean success))completion;
- (void)deleteShop:(B4SShop *)shop
        completion:(void (^)(Boolean success))completion;
- (void)saveCategory:(B4SCategory *)category
          completion:(void (^)(Boolean success))completion;
- (void)deleteCategory:(B4SCategory *)category
            completion:(void (^)(Boolean success))completion;
- (void)saveInteraction:(B4SInteraction *)interaction
             completion:(void (^)(Boolean success))completion;
- (void)deleteInteraction:(B4SInteraction *)interaction
               completion:(void (^)(Boolean success))completion;

- (void)updateAccount:(B4SUserAccount *)account
           completion:(void (^)(Boolean success))completion;
- (void)accountInfos:(void (^)(Boolean success, B4SUserAccount *accountInfos))completion;
- (void)createAccount:(NSString *)anEmail
             password:(NSString *)aPassword
            firstName:(NSString *)aFirstName
             lastName:(NSString *)aLastName
               street:(NSString *)aStreet
              zipCode:(NSString *)aZipCode
                 city:(NSString *)aCity
              country:(NSString *)aCountry
                phone:(NSString *)aPhone
              company:(NSString *)aCompany
           completion:(void (^)(Boolean success, Boolean alreadyExists))completion;

- (void)logout;
- (void)registerBeaconWithName:(NSString *)aName
                      category:(B4SCategory *)aCategory
                         group:(B4SGroup *)aGroup
                          shop:(B4SShop *)aShop
                  notification:(NSString *)aNotification
                         range:(int)aRangeValue;

- (NSSet *)beacons;

- (void)fullBeaconsList:(void (^)(NSArray *beacons))completion;
- (void)deleteBeacon:(NSString *)beaconId completion:(void (^)(Boolean success))completion;

- (void)sendZonesData:(void (^)(Boolean error))completion;
- (void)setHeading:(float)radians completion:(void (^)(Boolean success))completion;
- (void)setUserName:(NSString *)aName
          firstName:(NSString *)aFirstname
             gender:(B4SCustomerGender)aGender
              email:(NSString *)anEmail
        customerRef:(NSString *)aRef;
- (void)setAcknowledgeData:(NSString *)data;
- (void)sendSessionData:(B4SSession *)session;
- (void)updateBeacon:(B4SBeacon *)beacon;

- (void)dbRefreshTest:(CLLocation *)location cause:(B4SConfigUpdateCause)aCause;

// Request periodic update of beacons registered around the ios device
- (id)B4SsetPeriodicBeaconsUpdate:(BOOL)enabled;
- (BOOL)B4SisPeriodicBeaconsUpdateEnabled;
- (BOOL)hasBluetooth;

- (Boolean)isBeaconMode;
- (void)startBeaconMode;
- (void)stopBeaconMode;

- (void)notifyScanForBeacon:(B4SBeacon *)aBeacon forInteraction:(B4SInteraction *)anInteraction;

+ (B4SSingleton*) sharedInstance;
+ (B4SSingleton*) setupSharedInstanceWithAppId:(NSString *)anAppId adminMode:(Boolean)isAdminMode;

@end
