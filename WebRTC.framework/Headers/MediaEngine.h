//
//  MediaEngine.h
//  MediaEngine
//
//  Created by Thomas Gourgues on 21/08/12.
//  Copyright (c) 2012-2018 Thomas Gourgues. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "MediaEngineDelegate.h"
#import "MediaCryptoDelegate.h"
#import "WebRTC/RTCVideoRenderer.h"
#import "WebRTC/RTCAudioSession.h"
#import "WebRTC/RTCAudioSessionConfiguration.h"
#import "WebRTC/RTCDispatcher.h"

RTC_OBJC_EXPORT
@interface MediaEngine: NSObject

@property(nonatomic, assign) id <MediaEngineDelegate> delegate;
@property(nonatomic, assign) id <MediaCryptoDelegate> cryptoDelegate;

- (id)initWithLocalPeer:(NSString*)localPeerId video:(BOOL)video microphone:(BOOL)microphone constraints:(NSDictionary<NSString*, NSString*>*)constraints;
- (void)attachMediaStream:(id<RTCVideoRenderer>)renderer withStream:(MediaStream*)stream;
- (void)unattachMediaStream:(id<RTCVideoRenderer>)renderer withStream:(MediaStream*)stream;
- (MediaStream*)getMediaStream:(NSString*)peerId;
- (MediaStream*)getScreenShareStream;
- (BOOL)needSwitchToPstn;
- (BOOL)createConnectionWithPeer:(NSString*)peerId isMaster:(BOOL)isMaster;
- (BOOL)closeConnectionWithPeer:(NSString*)peerId;
- (BOOL)createAnswerForPeer:(NSString*)peerId;
- (BOOL)setDescriptionForPeer:(NSString*)peerId withSsrc:(long)ssrc type:(NSString*)type andSdp:(NSString*)sdp;
- (BOOL)setCandidateForPeer:(NSString*)peerId withsdpMid:(NSString*)sdpMid sdpIndex:(NSInteger)sdpMLineIndex andSdp:(NSString *)sdp;
- (BOOL)setPositionForPeer:(NSString*)peerId withAngle:(double)angle andPosition:(double)position;
- (BOOL)setPositionForPeer:(NSString*)peerId withAngle:(double)angle position:(double)position andGain:(float)gain;
- (BOOL)setGain:(float)gain forPeer:(NSString*)peerId;
- (void)setMute:(BOOL)mute;
- (void)setPeerMute:(NSString*)peerId mute:(BOOL)mute;
- (void)setAudioOptions:(BOOL)ns agc:(BOOL)agc ec:(BOOL)ec typingDetection:(BOOL)typingDetection;
- (NSString *)getLocalStats:(NSString*)peerId;
- (double)getLocalVuMeter;
- (double)getVuMeterForPeer:(NSString*)peerId;
- (void)enable3DAudio:(BOOL)enable;
- (void)setLoudSpeakerStatus:(BOOL)isEnable;
- (BOOL)isLoudSpeakerActive;
- (void)setHardwareAec:(BOOL)isHardwareAEC;
- (BOOL)isHardwareAec;
- (void)stop;
- (void)dealloc;
- (void)flipCamera:(void (^)(void))completionHandler;
- (void)startVideo;
- (void)startVideoWithDefaultFrontFacing:(BOOL)isDefaultFrontFacing;
- (void)stopVideo;
- (void)startScreenshare:(BOOL)broadcast completionHandler:(void (^)(bool success))completionHandler;
- (void)updateScreenshare:(CMSampleBufferRef)sampleBuffer;
- (void)stopScreenshare;
- (void)resetAudioDevices;

@end
