
#ifndef HAUOLI_CONSTANT_H
#define HAUOLI_CONSTANT_H

#define SAMPLING_RATE             96000
// #define SAMPLING_RATE             48000
// #define SAMPLING_RATE             44100
#define SOUND_SPEED               346600

#define CONTROLLER_STATE_STOP     0
#define CONTROLLER_STATE_READY    1
#define CONTROLLER_STATE_TRACKING 2

#define TRACKER_STATE_STOP        1
#define TRACKER_STATE_SYNC        2
#define TRACKER_STATE_SKEW        3
#define TRACKER_STATE_CANCEL      4
#define TRACKER_STATE_CALI        5
#define TRACKER_STATE_TRACKING    6

#define RESULT_OK                 1
#define RESULT_INIT_FAIL          2
#define RESULT_START_FAIL         3
#define RESULT_EXPIRED            4
#define RESULT_AUDIO_FAIL         5

// Audio Source
#define AUDIO_SOURCE_SP           0
#define AUDIO_SOURCE_AAUDIO       1
#define AUDIO_SOURCE_JAVA         3
#define AUDIO_SOURCE_USER         4

// Estimation Method
#define METHOD_TAP                0
#define METHOD_FMCW               1

// Gesture
#define GESTURE_NONE              0
#define GESTURE_TICKLE            1
#define GESTURE_HIT               2
#define GESTURE_PAT               3
#define GESTURE_AWAY              4
#define GESTURE_TOWARD            5
#define GESTURE_1CLICK_LONG       6
#define GESTURE_1CLICK_SHORT      7
#define GESTURE_2CLICK_LONG       8
#define GESTURE_2CLICK_SHORT      9
#define GESTURE_3CLICK_LONG       10
#define GESTURE_3CLICK_SHORT      11
#define GESTURE_4CLICK_LONG       12
#define GESTURE_4CLICK_SHORT      13

#endif // HAUOLI_CONSTANT_H
