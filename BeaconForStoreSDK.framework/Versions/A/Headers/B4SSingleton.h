//
//  B4SSingleton.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
// 

@import Foundation;
@import CoreLocation;

#include    "B4SCustomerGender.h"
#include    "B4SEnums.h"

@class B4SBeacon;
@class B4SRemoteNotification;
@class B4SInteraction;
@class B4SShop;
@class B4SLiveBeacon;
extern NSString *const kB4SNotificationProcessedNotification;

extern NSString *const kB4SBeaconNotificationName;
extern NSString *const kB4SBeaconOutOfRangeNotificationName;
extern NSString *const kB4SConfigurationUpdate;
extern NSString *const kB4SUserMoved;
extern NSString *const kB4SInteractionsUpdated;
extern NSString *const kB4SInteractionsUpdateValidated;

extern NSString *const kB4SNotifText;
extern NSString *const kB4SNotificationsCount;
extern NSString *const kB4SNotifInteractionData;
extern NSString *const kB4SNotifContentId;
extern NSString *const kB4SNotifNotificationDelay;
extern NSString *const kB4SNotifNotificationType;
extern NSString *const kB4SNotifCampaignId;
extern NSString *const kB4SNotifContentName;
extern NSString *const kB4SNotifCampaignName;
extern NSString *const kB4SNotifIncomingNotification;
extern NSString *const kB4SNotifOutgoingNotification;
extern NSString *const kB4SNotifBeaconId;
extern NSString *const kB4SNotifBeaconName;
extern NSString *const kB4SNotifNotificationId;
extern NSString *const kB4SNotifLocationAccuracy;
extern NSString *const kB4SNotifShopLatitude;
extern NSString *const kB4SNotifShopLongitude;
extern NSString *const kB4SNotifInteractionMaxDistance;
extern NSString *const kB4SNotifTimestamp;

extern NSString *const kB4SNotifDistance;
extern NSString *const kB4SNotifBeaconRef;
extern NSString *const kB4SNotifStoreRef;
extern NSString *const kB4SNotifShopName;
extern NSString *const kB4SNotifShopCity;
extern NSString *const kB4SNotifShopZipCode;

extern NSString *const kB4SNotifShopId;
extern NSString *const kB4SNotifDate;
extern NSString *const kB4SNotifActionId;
extern NSString *const kB4SNotifPageId;
extern NSString *const kB4SBeaconMajor;
extern NSString *const kB4SBeaconMinor;
extern NSString *const kB4SBeaconUdid;
extern  NSString    *const  kB4SNotifNotificationSource;
extern  NSString    *const  kB4SDisablePiningPlistKey;

B4SActionType B4SActionTypeForInteger ( NSInteger anIntValue );


#pragma mark -  UserProperties constants

/**
 *  User property first name
 */
extern NSString    *const      kB4SUserPropertyUserFirstNameKey;

/**
 *  User property last name
 */
extern NSString    *const      kB4SUserPropertyUserLastNameKey;

/**
 *  User property gender
 */
extern NSString    *const      kB4SUserPropertyUserGenderKey;

/**
 *  User property email
 */
extern NSString    *const      kB4SUserPropertyUsereMailKey;

/**
 *  User property language
 */
extern NSString    *const      kB4SUserPropertyUserLanguageKey;

/**
 *  User property customer ref
 */
extern NSString    *const      kB4SUserPropertyUserClientRefKey;


@class B4SSingleton;

@protocol B4SDelegate <NSObject>

@optional

/**
 *  This delegate method is called before displaying a notification to the user. Call the completion method with the original text, data and userInfos or modify those parematers as you see fit
 *
 *  @param aText      The notification text
 *  @param aData      The notification associated data
 *  @param userInfos  The notification userInfo
 *  @param completion The completion block to call with original or modified parameters
 */
- (void)customizeNotificationText:(NSString *)aText
                          andData:(NSString *)aData
                      andUserInfo:(NSMutableDictionary *)userInfos
                       completion:(void (^)(NSString *pushText, NSString *pushData, NSMutableDictionary *userInfos))completion;
@end

@interface B4SSingleton : NSObject


/**
 *  The delegate
 */
@property (nonatomic, weak)   id<B4SDelegate> delegate;

#pragma mark - Disable beacon scan in background

/**
 *  When set to NO, the SDK will stop using CoreLocation regions to look for beacons when the application is in background. Default value is YES
 * /!\ When the application is in foreground, the SDK keeps looking for beacons
 */
@property (nonatomic) BOOL beaconBackgroundScanEnabled;


#pragma mark - Customizing the notifications

/**
 *  The name of the filename played when a notification is shonw to the user. This must be the name a a file in CAF format ("Core Audio File") present in the app bundle
 */
@property (nonatomic, retain) NSString *notificationSoundname;

#pragma mark - User Properties

/**
 *  Store a integer property about the user. This value will be sent to the server
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value.
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withInteger:(NSInteger)number DEPRECATED_MSG_ATTRIBUTE("Use [B4SSingleton setUserProperty: ... andLocalOnly:] methods");

/**
 *  Store a float property about the user. This value will be sent to the server
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value.
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withFloat:(float)number DEPRECATED_MSG_ATTRIBUTE("Use [B4SSingleton setUserProperty: ... andLocalOnly:] methods");

/**
 *  Store a string property about the user. This value will be sent to the server
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value. Pass [NSNull null] to delete a previously existing value
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withString:(NSString *)string DEPRECATED_MSG_ATTRIBUTE("Use [B4SSingleton setUserProperty: ... andLocalOnly:] methods");

/**
 *  Store a gender property about the user. This value will be sent to the server
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value. Pass B4SCustomerGender_UNDEFINED to delete a previously existing value
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withGender:(B4SCustomerGender)gender DEPRECATED_MSG_ATTRIBUTE("Use [B4SSingleton setUserProperty: ... andLocalOnly:] methods");

/**
 *  Store a Array property about the user. This value will be sent to the server
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value. Pass [NSNull null] to delete a previously existing value. The array cannot contain another array, nor contains types other that NSString, NSNumber, NSDate. All objects inside the array must have the same data type
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withArray:(NSArray *)array DEPRECATED_MSG_ATTRIBUTE("Use [B4SSingleton setUserProperty: ... andLocalOnly:] methods");

/**
 *  Store a date property about the user. This value will be sent to the server
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value. Pass [NSNull null] to delete a previously existing value
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withDate:(NSDate *)date DEPRECATED_MSG_ATTRIBUTE("Use [B4SSingleton setUserProperty: ... andLocalOnly:] methods");

/**
 *  Store a integer property about the user
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value.
 *  @param localOnly If TRUE the user property won't be sent to the server and thus can only be user for local substitution
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withInteger:(NSInteger)number andLocalOnly:(BOOL)localOnly;

/**
 *  Store a float property about the user
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value.
 *  @param localOnly If TRUE the user property won't be sent to the server and thus can only be user for local substitution
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withFloat:(float)number andLocalOnly:(BOOL)localOnly;

/**
 *  Store a string property about the user
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value. Pass [NSNull null] to delete a previously existing value
 *  @param localOnly If TRUE the user property won't be sent to the server and thus can only be user for local substitution
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withString:(NSString *)string andLocalOnly:(BOOL)localOnly;

/**
 *  Store a gender property about the user
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value. Pass B4SCustomerGender_UNDEFINED to delete a previously existing value
 *  @param localOnly If TRUE the user property won't be sent to the server and thus can only be user for local substitution
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withGender:(B4SCustomerGender)gender andLocalOnly:(BOOL)localOnly;

/**
 *  Store a Array property about the user
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value. Pass [NSNull null] to delete a previously existing value. The array cannot contain another array, nor contains types other that NSString, NSNumber, NSDate. All objects inside the array must have the same data type
 *  @param localOnly If TRUE the user property won't be sent to the server and thus can only be user for local substitution
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withArray:(NSArray *)array andLocalOnly:(BOOL)localOnly;

/**
 *  Store a date property about the user
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *  @param number The value. Pass [NSNull null] to delete a previously existing value
 *  @param localOnly If TRUE the user property won't be sent to the server and thus can only be user for local substitution
 *
 *  @return Returns TRUE, if the value is valid, FALSE otherwise or if more than 20 properties have been set.
 */
- (BOOL)setUserProperty:(NSString *)key withDate:(NSDate *)date andLocalOnly:(BOOL)localOnly;

/**
 *  Deletes an existing user property
 *
 *  @param key    The key is a string. It should use reverse-dns-like notation to be used as a domain. For instance, the user hometown should use a "user.hometown" key
 *
 *  @return Returns TRUE, if the value is valid, FALSE if the key didn't exist
 */
- (BOOL)deleteUserProperty:(NSString *)key;

/**
 *  Get the number of user properties
 *
 *  @return Get the number of used user properties of the 20 availables
 */
- (NSUInteger)userPropertyCount;

#pragma mark - Push notifications

/**
 *  Enable the Push notification feature
 */
- (void)enablePushNotifications;


/*
 * Enable stop location detection. This is FALSE by default.
 */

@property (nonatomic) BOOL       enableStopLocationDetection;

/**
 *  Complete the registration for Push notifications. This method MUST be called from application:didRegisterForRemoteNotificationsWithDeviceToken: otherwise the device won't receive Push notifications.
 *
 *  @param deviceToken The token passed as a parameter to application:didRegisterForRemoteNotificationsWithDeviceToken:
 */
- (void)registerPushNotificationDeviceToken:(NSData *)deviceToken;

#pragma mark - Temporarly disable notifications

/**
 *  Sets this to FALSE to display the notifications displayed by the SDK. Default value is TRUE
 *  Do NOT set this before calling startStandAloneMode or your call will be ignored
 */
@property(nonatomic)    BOOL displayNotifications;

#pragma mark - Showing notifications
/**
 *  This methods must be called from your app delegate application:didReceiveLocalNotification:
 *
 *  @param userInfo The userInfo dictionary received by the application:didReceiveLocalNotification: method
 */
- (void)notificationFeedback:(NSDictionary *)userInfo;

#pragma - User knowledge

/**
 * YES if location tracking is enabled. Default value is YES. Use this to override the value set by the server. This value is ignored if the ATR mode is disabled for your application
 */
@property (nonatomic) BOOL enablePositionTracking;

#pragma - User home & workplace

/**
 The coordinates of the user's home. If the coordinates cannot be determined, return an invalid value. Use CLLocationCoordinate2DIsValid() ( https://developer.apple.com/reference/corelocation/1423806-cllocationcoordinate2disvalid?language=objc ) to check if coordinate is valid
 */
@property   (readonly)  CLLocationCoordinate2D  userHomeCoordinates;


/**
 The coordinates of the user's workplace. If the coordinates cannot be determined, return an invalid value. Use CLLocationCoordinate2DIsValid() ( https://developer.apple.com/reference/corelocation/1423806-cllocationcoordinate2disvalid?language=objc ) to check if coordinate is valid
 */
@property   (readonly)  CLLocationCoordinate2D  userWorkplaceCoordinates;

#pragma mark - Initialisation
/**
 *  Get the SDK singleton
 *
 *  @return Returns the SDK Singleton or nil if [B4SSingleton setupSharedInstanceWithAppId:] hasn't been called previously
 */
+ (B4SSingleton *)sharedInstance;

/**
 *  Initialize the SDK
 *
 *  @param anAppId Your BeaconForStore app ID. Use the Neer.By web manager to get this identifier: https://manager.neer.by
 *
 *  @return The B4S Singleton
 */
+ (B4SSingleton *)setupSharedInstanceWithAppId:(NSString *)anAppId DEPRECATED_MSG_ATTRIBUTE("Set the 'Neer.By AppID' key to the Info.plist file instead. Refer to the documentation");

/**
 *  Initialize the SDK using the App ID found in the 'Neer.By AppID' key from the Info.plist. If the key is missing, the SDK will log an error
 *
 *  @return The B4S Singleton
 */
+ (B4SSingleton *)setupSharedInstance;


/**
 *  Start to listen to beacons. This method must be called AFTER [B4SSingleton setupSharedInstanceWithAppId:]
 */

- (void)start;

#pragma  mark - GPDR Purposes
/**

 @param purposeName Purpose fully qualified name
 @return Purpose value, casted as a BOOL. Might return funky results if user property type is not an integer
 */
- (BOOL)statusForPurpose:(NSString *)purposeName;

- (void)setStatus:(BOOL)status forPurpose:(NSString *)purposeName;


#pragma mark - Shop mode
/**
 Check if the user is currently in a shop
 
 @return Nil if the user is not in a shop, a valid B4SShop instance otherwise
 */
- (B4SShop *)currentShop;


@end
