
#ifndef HauoliTrackerWrapper_h
#define HauoliTrackerWrapper_h

#import <MediaPlayer/MediaPlayer.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class HauoliTracker;

@interface HauoliTracker : NSObject

@end

@interface HauoliTracker () 
- (int)initTracker:(int)num_spk 
                    num_mic:(int)num_mic 
                    init_pos:(double *)init_pos 
                    spk_pos:(double *)spk_pos 
                    mic_pos:(double *)mic_pos;
- (int)start;
- (int)stop;
- (double)getDist;
- (void)getDists:(double *)dists;
- (void)getPos:(double *)pos;
- (int)getState;
- (double)getPower;
// General Config
- (int)getB;
- (void)getFc:(int *)f;
- (void)getPlayBuffer:(short int *)buf spk_idx:(int)spk_idx;
- (bool)setDistEstMethod:(int)method;
- (bool)setB:(int)b;
- (bool)setFc:(int *)f;
- (bool)setSkipTime:(double)time;
- (bool)setUseFile:(bool)if_file;
- (bool)setRecordAudio:(bool)if_record;
- (bool)setAudioSource:(int)src;
- (bool)setAllowReset:(bool)allowed;
- (bool)pushAudio:(int8_t *)y num_elem:(int)num_elem;
- (bool)pushAudio2:(int16_t *)y num_elem:(int)num_elem;
// Tap
- (int)getNSeq;
- (int)getNSeqUp;
- (int)getMaxTap;
- (int)getTapStep;
- (void)getCirDiff:(double *)cir_dif_real cir_dif_imag:(double *)cir_dif_imag;
- (bool)setSeq:(int)num_seq num_seq_up:(int)num_seq_up b:(int)b;
- (bool)setNSeq:(int)num_seq;
- (bool)setNSeqUp:(int)num_seq_up;
- (bool)setMaxTap:(int)max_tap;
- (bool)setTapStep:(int)tap_step;
- (bool)setAutoThrd:(bool)auto_thrd;
// FMCW
- (double) getChirpLenS;
- (bool)   setChirpLenS:(double)chirp_len_s seq_len_s:(double)seq_len_s;
- (bool)   setCancelLenS:(double)len;
- (bool)   setAGC:(bool)on;
- (bool)   setPlayAudio:(bool)play;
- (bool)   setIfProcessAudio:(bool)process;
// Gesture
- (int)getGesture;
- (int)getGestCnt;
- (bool)enableGesture:(bool)enabled;
// UI Related
- (bool)trajCleaned;

@end

#endif /* HauoliTrackerWrapper_h */
