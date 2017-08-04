//
//  BYBOptoStimmerManager.h
//
//  Core Bluetooth OptoStimmer Class handles communication to the OptoStimmer
//
//  Created by Greg Gage on 4/14/13.
//  Copyright (c) 2013 Backyard Brains. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>
#include "BYBOptoStimmer.h"

#define BYB_OPTOSTIMMER_SERVICE_UUID  0xB2B0
#define BYB_OPTOSTIMMER_CHAR_FREQUENCY_UUID  0xB2B1
#define BYB_OPTOSTIMMER_CHAR_PULSEWIDTH_UUID  0xB2B2
#define BYB_OPTOSTIMMER_CHAR_DURATION_IN_5MS_INTERVALS_UUID  0xB2B3
#define BYB_OPTOSTIMMER_CHAR_RANDOMMODE_UUID  0xB2B4
#define BYB_OPTOSTIMMER_STIM_LEFT_UUID  0xB2B5
#define BYB_OPTOSTIMMER_STIM_RIGHT_UUID  0xB2B6
#define BYB_OPTOSTIMMER_CHAR_GAIN_UUID  0xB2B7
#define BYB_OPTOSTIMMER_CHAR_PULSE_WIDTH_SEC_UUID  0xB2B8

#define BATTERY_SERVICE_UUID 0x180F
#define BATTERY_CHAR_BATTERYLEVEL_UUID 0x2A19

#define DEVICE_INFO_SERVICE_UUID 0x180A
#define DEVICE_INFO_CHAR_HARDWARE_UUID 0x2A27
#define DEVICE_INFO_CHAR_FIRMWARE_UUID 0x2A26


@protocol BYBOptoStimmerManagerDelegate <NSObject>
@required
- (void) didSearchForOptoStimmeres: (NSArray*)foundOptoStimmeres;
- (void) didConnectToOptoStimmer: (BOOL)success;
- (void) didFinsihReadingOptoStimmerValues;
- (void) didDisconnectFromOptoStimmer;
- (void) optoStimmerReady;

@optional
- (void) hadBluetoothError: (int) CMState;
@end

@interface BYBOptoStimmerManager : NSObject <CBCentralManagerDelegate , CBPeripheralDelegate >
{
    UInt16 tempPulseWidthFirst;
    UInt16 tempPulseWidthSecond;
    float tempDuration;
    float tempFrequency;
    long maximumSignalStrength;
}

@property (strong, nonatomic) NSMutableArray *peripherals;
@property (strong, nonatomic) CBCentralManager *CM;
@property (strong, nonatomic) BYBOptoStimmer *activeOptoStimmer;

//BYBOptoStimmerManager Delegate
- (id)delegate;
- (void)setDelegate:(id)newDelegate;

-(int) searchForOptoStimmeres:(int) timeout;
-(int) connectToOptoStimmer:(BYBOptoStimmer *) optoStimmer;
-(int) disconnectFromOptoStimmer;
-(void) sendMoveCommandToActiveOptoStimmer: (BYBMovementCommand) command;
-(void) sendUpdatedSettingsToActiveOptoStimmer;

-(void) readValue: (int)serviceUUID characteristicUUID:(int)characteristicUUID;
-(void) writeValue:(int)serviceUUID characteristicUUID:(int)characteristicUUID data:(NSData *)data;
-(void) notification:(int)serviceUUID characteristicUUID:(int)characteristicUUID on:(BOOL)on;


-(UInt16) swap:(UInt16)s ;
-(const char *) CBUUIDToString:(CBUUID *) UUID ;
-(const char *) UUIDToString:(NSUUID*)UUID;
-(int) compareCBUUID:(CBUUID *) UUID1 UUID2:(CBUUID *)UUID2;
-(int) compareCBUUIDToInt:(CBUUID *)UUID1 UUID2:(UInt16)UUID2 ;
-(UInt16) CBUUIDToInt:(CBUUID *) UUID;
-(CBService *) findServiceFromUUID:(CBUUID *)UUID p:(CBPeripheral *)p;
-(CBCharacteristic *) findCharacteristicFromUUID:(CBUUID *)UUID service:(CBService*)service ;
- (const char *) centralManagerStateToString: (int)state;
- (void) printPeripheralInfo:(CBPeripheral*)peripheral;
- (void) printKnownPeripherals;

@end
