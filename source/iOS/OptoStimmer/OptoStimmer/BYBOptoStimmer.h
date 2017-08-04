//
//  BYBOptoStimmer.h
//  OptoStimmer
//
//  Created by Greg Gage on 4/17/13.
//  Copyright (c) 2013 Backyard Brains. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import <Foundation/Foundation.h>


#define OPTOSTIMMER_TURN_TIMEOUT 0.4

typedef enum {
    moveLeft=1,
    moveRight,
} BYBMovementCommand;

@interface BYBOptoStimmer : NSObject

@property (nonatomic, copy) NSNumber *randomMode;
@property (nonatomic, copy) NSNumber *frequency;
@property (nonatomic, copy) NSNumber *gain;
@property (nonatomic, copy) NSNumber *pulseWidth;
@property (nonatomic, copy) NSNumber *duration;
@property (strong, nonatomic) CBPeripheral *peripheral;
@property (nonatomic, copy) NSNumber *batteryLevel;

@property (nonatomic, copy) NSString *hardwareVersion;
@property (nonatomic, copy) NSString *firmwareVersion;

@property (nonatomic, copy) NSNumber *isLoadingParameters;


//- (void) readSettingsFromOptoStimmer;
- (void) goLeft;
- (void) goRight;
- (void) updateSettings;
- (NSString *) getStimulationString;

//BYBOptoStimmer Delegate
- (id)delegate;
- (void)setDelegate:(id)newDelegate;


@end


@protocol BYBOptoStimmerDelegate <NSObject>
@required
- (void) optoStimmerHasChangedSettings:(BYBOptoStimmer *)optoStimmer;
- (void) optoStimmer: (BYBOptoStimmer *)optoStimmer hasMovementCommand:(BYBMovementCommand) command;
@end

