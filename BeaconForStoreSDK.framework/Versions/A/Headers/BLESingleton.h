//
//  BLESingleton.h
//  BleMessaging
//
//  Created by Christophe Janot on 01/10/2015.
//  Copyright © 2015 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BLEClient.h"
#import "BLEMessage.h"
#import "B4SConstants.h"
#import "B4SShop.h"

#define BLE_MESSAGING_SERVICE_UUID     @"38F87FEB-9D0D-4368-A837-7C854100647F"

#define RID_CHARACTERISTIC_UUID  @"A27FDB17-EC1E-4506-BFDA-79FB7882BA33"
#define RCD_CHARACTERISTIC_UUID  @"53A7C23B-DAFE-47B8-A404-EA22BA5C0835"
#define RUI_CHARACTERISTIC_UUID  @"9E6C762F-B8EA-4599-895A-B0B4DABE7B21"
#define NME_CHARACTERISTIC_UUID  @"A043A760-C76F-44DF-94B2-72B8F05323EC"
#define WRT_CHARACTERISTIC_UUID  @"1E4697AF-A4A3-4753-AADA-5539482A286F"
#define REA_CHARACTERISTIC_UUID  @"651EE962-1C1C-4298-AE70-B23176691174"

extern NSString *const kBLEMessagingClientINNotification;
extern NSString *const kBLEMessagingClientOUTNotification;
extern NSString *const kBLEMessagingMessageNotification;

@protocol BLEMessagingDelegate <NSObject>

@optional
/**
 Delegate method to notifying a client entry.
 */
- (void)newClientEntered:(BLEClient *)aClient;
/**
 Delegate method to notifying a client exit.
 */
- (void)clientExited:(BLEClient *)aClient;
/**
 Delegate method to notifying an incoming message.
 */
- (void)messageReceived:(BLEMessage *)aMessage;

@end

@interface BLESingleton : NSObject
/**
 Last message received from a client device
 */
@property (nonatomic, retain) BLEMessage *lastReceivedMessage;

- (instancetype)setupSSID:(NSString *)aSSID
            encryptionKey:(NSString *)aKey
             macAddresses:(NSArray *)macAddresses
                 isMaster:(Boolean)isMaster;
- (void)setUserId:(NSString *)userId userCompData:(NSString *)compData userDisplayName:(NSString *)displayName;
- (void)shopIn:(B4SShop *)aShop;
- (void)shopOut;
+ (NSString *)encryptionKey;
+ (CBPeripheralManager *)peripheralManager;
+ (instancetype)sharedInstance;
@end
