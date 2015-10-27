//
//  BLEMessage.h
//  BleMessaging
//
//  Created by Christophe Janot on 01/10/2015.
//  Copyright © 2015 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The type of message send/receive
 */
typedef NS_ENUM(NSInteger, BLEMessageType) {
    BLEMessageType_NONE,
    /**
     * The message with this type will automaticaly display a local notification
     */
    BLEMessageType_NOTIFICATION,
    /**
     * This is a simple text message. No local notification will be generated.
     */
    BLEMessageType_TEXT,
    /**
     * This is an inter-application data message.
     */
    BLEMessageType_DEEPLINK,
    /**
     * Open URL in navigator.
     */
    BLEMessageType_EXURL,
    /**
     * Open URL in webview.
     */
    BLEMessageType_INURL,
    /**
     *
     */
    BLEMessageType_RID,
    /**
     *
     */
    BLEMessageType_RCD,
    /**
     *
     */
    BLEMessageType_NME
};

BLEMessageType B4SMessageTypeForInteger ( NSInteger anIntValue );

@interface BLEMessage : NSObject
/**
 Text of the received message without its header
 */
@property (nonatomic, retain) NSString *messageText;
@property (nonatomic) BLEMessageType messageType;
@property (nonatomic, retain) NSString *encryptedData;

- (instancetype)initWithMessageText:(NSString *)messageText andType:(BLEMessageType)messageType;
- (NSString *)toString;
+ (BLEMessage *)decodeMessage:(NSString *)aStr;
+ (NSString *)encryptMessageText:(NSString *)messageText
                         andType:(BLEMessageType)messageType;

@end
