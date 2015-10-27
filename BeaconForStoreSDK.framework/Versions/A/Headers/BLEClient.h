//
//  BLEClients.h
//  BleMessaging
//
//  Created by Christophe Janot on 01/10/2015.
//  Copyright © 2015 Ezeeworld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "BLEMessage.h"

@interface BLEClient : NSObject

/**
 Internal uuid (RUI). Format is RSSI:sssss
 */
@property (nonatomic, retain) NSString *innerUUID;
/**
 Device owner unique ID (RID)
 */
@property (nonatomic, retain) NSString *deviceOwnerId;
/**
 Device owner complementary data (RCD)
 */
@property (nonatomic, retain) NSString *deviceOwnerData;
/**
 Device owner name as seen by master devices (NME)
 */
@property (nonatomic, retain) NSString *deviceOwnerDisplayName;
/**
 Last message received from a client device
 */
@property (nonatomic, retain) NSString *lastReceivedMessage;

/**
 Date the device was first discovered
 */
@property (nonatomic, retain) NSDate * entryDate;
/**
 Last time the device was seen by the CoreBluetooth scanner
 */
@property (nonatomic, retain) NSDate * lastSeenDate;

/**
 CoreBluetooth peripheral for the device
 */
@property (nonatomic, retain) CBPeripheral *peripheral;

@property (nonatomic) Boolean deviceAuthorized;

/**
 * Send a message to the device
 */
- (Boolean)sendMessage:(BLEMessage *)aMessage;
/**
 Return entry date ordered clientsList
 */
+ (NSArray *)list;
/**
 Return the numbers of authorized clients.
 */
+ (int)count;
+ (BLEClient *)getPeripheralClient:(CBPeripheral *)aPeripheral;
/**
 This method is called every time a device is detected by the CoreBlutooth scanner.
 If the device is new, it is added to the device table.
 */
+ (BLEClient *)peripheralSense:(CBPeripheral *)aPeripheral
                      withName:(NSString *)aPeripheralName
                centralManager:(CBCentralManager *)centralManager;
/**
 Called on a regular basis to detect peripherals that went away.
 */
+ (void)outOfSightDevicesDetection;
/**
 Remove given client
 */
- (void)removeClient;

@end
