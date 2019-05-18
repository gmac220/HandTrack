//
//  ViewController.m
//  TrackHandSimpleIOS
//
//  Created by yichao on 2019/5/13.
//  Copyright © 2019 Hauoli. All rights reserved.
//

#import "ViewController.h"

#import "HauoliConst.h"
#import "HauoliTracker.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIView *circleView;
@property (weak, nonatomic) IBOutlet UILabel *distanceLabel;
@end

@implementation ViewController
HauoliTracker *hauoliTracker;
double *estDists;
CGFloat screenWidth;
CGFloat screenHeight;
double oldDist;
Boolean ended;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    _circleView.layer.cornerRadius = 25;  // half the width/height
    int nMic = 1;
    int nSpk = 1;
    int nDim = 2;
    double *initPos = (double *)malloc(sizeof(double)*nDim);
    double *spkPos  = (double *)malloc(sizeof(double)*nSpk*nDim);
    double *micPos  = (double *)malloc(sizeof(double)*nMic*nDim);
    screenWidth = [UIScreen mainScreen].bounds.size.width;
    screenHeight = [UIScreen mainScreen].bounds.size.height;
    
    
    // set the initial distance from hand to mic = 100mm
    initPos[0] = 0;
    initPos[1] = -100;
    // the position of the speaker on iPhone: [0, 0]
    spkPos[0] = 0;
    spkPos[1] = 0;
    // the position of the microhpone on iPhone: [0, 0]
    micPos[0] = 0;
    micPos[1] = 0;
    
    hauoliTracker = [[HauoliTracker alloc] init];
    [hauoliTracker initTracker:nSpk num_mic:nMic init_pos:initPos spk_pos:spkPos mic_pos:micPos];
    
    //-------------------------------
    // Other Configuration (don't need to change)
    [hauoliTracker setDistEstMethod:METHOD_TAP];
    [hauoliTracker setAudioSource:AUDIO_SOURCE_USER];
    [hauoliTracker setSeq:30 num_seq_up:240 b:6000];
    [hauoliTracker setMaxTap:120];
    [hauoliTracker setTapStep:10];
    [hauoliTracker setAllowReset:false];
    [hauoliTracker setAutoThrd:true];
    [hauoliTracker setRecordAudio:false];
    [hauoliTracker setUseFile:false];
    [hauoliTracker enableGesture:false];
    
    //-------------------------------
    // Start tracking
    
    estDists = (double *)malloc(sizeof(double)*nMic);
    [hauoliTracker start];
    NSLog(@"viewloaded %f", [hauoliTracker getDist]);
    oldDist = 0.0;
    ended = false;
    

}
- (IBAction)startTracking:(id)sender {
   
    [hauoliTracker getDists:estDists];
    NSNumber *myDoubleNumber;
    double xOrigin = _circleView.frame.origin.x;
    double yOrigin = _circleView.frame.origin.y;
    if (ended){
        [hauoliTracker start];
        ended = false;
    }
    
    while(oldDist != [hauoliTracker getDist]){
        NSLog(@"dist = %f", estDists[0]);
        myDoubleNumber = [NSNumber numberWithDouble:estDists[0]];
        _distanceLabel.text =  [myDoubleNumber stringValue];
        if (estDists[0] < 0 || estDists[0] > screenWidth || estDists[0] > screenHeight){
            _circleView.center = CGPointMake(xOrigin, yOrigin);
        }else{
            _circleView.center = CGPointMake(estDists[0], estDists[0]);
        }
        
        [NSThread sleepForTimeInterval:0.05];
        oldDist = estDists[0];
    }
}

- (IBAction)stop:(id)sender {
    NSLog(@"pressed stop");
    ended = true;
    [hauoliTracker stop];
}


@end
