//
//  BYBOptoStimmerSettingsViewController.h
//  OptoStimmer
//
//  Created by Greg Gage on 4/17/13.
//  Copyright (c) 2013 Backyard Brains. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BYBOptoStimmerManager.h"
#import "OBSlider.h"
@protocol BYBSettingsDelegate;


@interface BYBOptoStimmerSettingsViewController : UIViewController <UITextFieldDelegate,UITextViewDelegate>{
    //SCTableViewModel *tableViewModel;
    //IBOutlet UITableView *tableView;
    __weak IBOutlet UIImageView *stimImage;
}
@property (strong, nonatomic) IBOutlet OBSlider *durationSlider;
@property (strong, nonatomic) IBOutlet OBSlider *freqSlider;
@property (strong, nonatomic) IBOutlet OBSlider *pulseWidthSlider;
- (IBAction)pulseWidthChange:(id)sender;
- (IBAction)frequencyChanged:(id)sender;
- (IBAction)durationChanged:(id)sender;
@property (strong, nonatomic) IBOutlet UITextField *durationTI;
@property (strong, nonatomic) IBOutlet UITextField *frequencyTI;
@property (strong, nonatomic) IBOutlet UITextField *pulseWidthTi;
@property (strong, nonatomic) IBOutlet UIScrollView *scrollViewBackground;

@property (strong, nonatomic) BYBOptoStimmer * optoStimmer;
- (IBAction)applyBtnClick:(id)sender;

@property (nonatomic, assign) id <BYBSettingsDelegate> masterDelegate;

@end




@protocol BYBSettingsDelegate <NSObject>
- (void) applySettings;

@end

