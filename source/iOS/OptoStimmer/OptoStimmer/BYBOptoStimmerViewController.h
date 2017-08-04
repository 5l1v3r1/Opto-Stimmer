//
//  BYBOptoStimmerViewController.h
//  OptoStimmer
//
//  Created by Greg Gage on 4/13/13.
//  Copyright (c) 2013 Backyard Brains. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>
#import "BYBOptoStimmerManager.h"
#import "BYBOptoStimmerSettingsViewController.h"
#import "GPUImage.h"

@interface BYBOptoStimmerViewController : UIViewController <BYBOptoStimmerManagerDelegate, BYBOptoStimmerDelegate, BYBSettingsDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, GPUImageMovieWriterDelegate>


    @property (nonatomic, strong) UIImagePickerController *cameraUI;
    @property (strong, nonatomic) IBOutlet UIButton *sessionBTN;
    @property (strong, nonatomic) IBOutlet UIImageView *gpuImageView;

    - (IBAction)connectButtonClicked:(id)sender ;
    - (IBAction)favoritesClicked:(id)sender ;
    - (IBAction)startSession:(id)sender;
    - (void) optoStimmerHasChangedSettings:(BYBOptoStimmer *)optoStimmer;
    - (void) optoStimmer: (BYBOptoStimmer *)optoStimmer hasMovementCommand:(BYBMovementCommand) command;
    - (void) didFinsihReadingOptoStimmerValues;
    - (void) applySettings;
@end

