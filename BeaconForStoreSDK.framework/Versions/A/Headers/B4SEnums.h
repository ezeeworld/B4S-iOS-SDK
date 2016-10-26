//
//  B4SEnums.h
//  BeaconForStoreSDK
//
//  Created by Francois Reboursier on 21/07/15.
//  Copyright (c) 2015 Ezeeworld. All rights reserved.
//

#ifndef BeaconForStoreSDK_Header_h
#define BeaconForStoreSDK_Header_h

typedef NS_ENUM(NSInteger, B4SNetworkStatus) {
    B4SNetworkStatus_UNKNOWN,
    B4SNetworkStatus_NONE,
    B4SNetworkStatus_WIFI,
    B4SNetworkStatus_WWAN
};

typedef NS_ENUM(NSInteger, B4SSpeedIndices) {
    B4SSpeedIndices_UNKNOWN,
    B4SSpeedIndices_STATIC,
    B4SSpeedIndices_WALK,
    B4SSpeedIndices_CITY_DRIVE,
    B4SSpeedIndices_SPEED,
    B4SSpeedIndices_HIGHWAY_DRIVE
};

typedef NS_ENUM(NSInteger, B4SConfigUpdateCause) {
    B4SConfigUpdateCause_SDKLOOP,
    B4SConfigUpdateCause_MOVE,
    B4SConfigUpdateCause_BEACONREG,
    B4SConfigUpdateCause_IBSDKLOOP,
    B4SConfigUpdateCause_REGIONIN,
    B4SConfigUpdateCause_REGIONOUT,
    B4SConfigUpdateCause_APPSTART,
    B4SConfigUpdateCause_DEMO,
    B4SConfigUpdateCause_NOTIFICATION
};

typedef NS_ENUM(NSInteger, B4SSessionEndCause) {
    kB4SSESSION_END_RANGEOUT,
    kB4SSESSION_END_SWAP,
    kB4SSESSION_END_NOBEACONS,
    kB4SSESSION_END_FORCED,
    kB4SSESSION_END_MAXCOUNT,
    kB4SSESSION_END
};

/**
 *  The source of a notification shown to the user
 */
typedef NS_ENUM(NSInteger, B4SNotificationSource){
    
    /**
     *  Unknown source
     */
    B4SNotificationSourceUnknown = 0,
    /**
     *  A hardware beacon
     */
    B4SNotificationSourceBeacon = 1,
    /**
     *  A push notification
     */
    B4SNotificationSourcePushNotification = 2,
    
    /**
     *  A geofence
     */
    B4SNotificationSourceGeofence = 3
};


typedef NS_ENUM(NSInteger, B4SiOSAddTrackingStatus) {
    B4SiOSAddTrackingStatusOff = 0,
    B4SiOSAddTrackingStatusOn = 1,
    B4SiOSAddTrackingStatusUnknown = 2
};

/**
 *  The type of an action associated with a notification
 */
typedef NS_ENUM(NSInteger, B4SActionType){
    /**
     *  No internal action was required.
     */
    B4SActionType_NONE,
    /**
     *  The user chose not to open the notification
     */
    B4SActionType_REJECT,
    /**
     *
     */
    B4SActionType_BUSY,
    /**
     * The interaction is configured to open a predefined page in your application. Use [notificationData.userInfo objectForKey:kB4SNotifPageId] to know the page to open
     */
    B4SActionType_INAPP,
    /**
     *  A webview was opened to display the url set in the interaction
     */
    B4SActionType_INAPPWEB,
    /**
     *  An URL was open in Safari, or an URL Scheme was opened
     */
    B4SActionType_WEB,
    /**
     *  Unused
     */
    B4SActionType_IMAGE,
    /**
     *  Unused
     */
    B4SActionType_TEXT
};

/**
 *  Is the device moving
 */
typedef NS_ENUM(NSInteger, B4SMovement) {
    /**
     *  The devide is static
     */
    B4SMovement_STATIC,
    /**
     *  The device is moving
     */
    B4SMovement_MOVING
};


/**
 *  The type of an event generated within the customer journey
 */
typedef NS_ENUM(NSInteger, B4SJourneyEventType) {
    /**
     *  Notification shown to the user
     */
    B4SJourneyEventType_NOTIFICATION = 0,
    /**
     *  Shop entry
     */
    B4SJourneyEventType_SHOPIN = 1,
    /**
     *  Shop exit
     */
    B4SJourneyEventType_SHOPOUT = 2,
    /**
     *  Encounter a beacon (entered in the beacon radio range)
     */
    B4SJourneyEventType_BEACON = 3,
    /**
     *  The user has read a notification
     */
    B4SJourneyEventType_NOTIFICATIONREAD = 4,
    /**
     *  The user navigated to a manual tag within the app
     */
    B4SJourneyEventType_MANUALTAG = 5
};

#endif
