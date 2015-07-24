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

typedef NS_ENUM(NSInteger, B4SBeaconStatus) {
    B4SBeaconStatus_UNDEFINED,
    B4SBeaconStatus_NO_BEACON,
    B4SBeaconStatus_MULTIPLE_BEACONS,
    B4SBeaconStatus_QUERY_BEACON,
    B4SBeaconStatus_NEW_BEACON,
    B4SBeaconStatus_REGISTERED,
    B4SBeaconStatus_REG_ERROR,
    B4SBeaconStatus_EXISTING,
    B4SBeaconStatus_SRV_ERROR,
    B4SBeaconStatus_UNAUTHORIZED
};

typedef NS_ENUM(NSInteger, B4SConfigUpdateCause) {
    B4SConfigUpdateCause_SDKLOOP,
    B4SConfigUpdateCause_MOVE,
    B4SConfigUpdateCause_BEACONREG,
    B4SConfigUpdateCause_IBSDKLOOP,
    B4SConfigUpdateCause_REGIONIN,
    B4SConfigUpdateCause_REGIONOUT,
    B4SConfigUpdateCause_APPSTART,
    B4SConfigUpdateCause_DEMO
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

enum B4SMovement {
    kB4SMAPMOVE_NO,
    kB4SMAPMOVE_YES
};
typedef enum B4SMovement B4SMovement;

#endif
