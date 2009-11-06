/* cocos2d for iPhone
 *
 * http://www.cocos2d-iphone.org
 *
 * Copyright (C) 2009 Ricardo Quesada
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the 'cocos2d for iPhone' license.
 *
 * You will find a copy of this license within the cocos2d for iPhone
 * distribution inside the "LICENSE" file.
 *
 */

#import <Foundation/Foundation.h>
#import "CCNode.h"

#pragma mark -
#pragma mark CCSpriteFrame

/** A CCSpriteFrame is an NSObject that encapsulates a CGRect.
 * And a CGRect represents a frame within the CCSpriteManager
 */
@interface CCSpriteFrame : NSObject
{
	CGRect	rect;
}
/** rect of the frame */
@property (nonatomic,readwrite) CGRect rect;

/** create a CCSpriteFrame with a CGRect */
+(id) frameWithRect:(CGRect)frame;
/** initializes a CCSpriteFrame with a CGRect */
-(id) initWithRect:(CGRect)frame;
@end

#pragma mark -
#pragma mark CCAnimation

/** an Animation object used within Sprites to perform animations */
@interface CCAnimation : NSObject <CCAnimation>
{
	NSString			*name;
	float				delay;
	NSMutableArray		*frames;
}

@property (nonatomic,readwrite,assign) NSString *name;

/** delay between frames in seconds */
@property (nonatomic,readwrite,assign) float delay;
/** array of frames */
@property (nonatomic,readonly) NSMutableArray *frames;

/** creates a CCAnimation with a name and delay between frames */
+(id) animationWithName:(NSString*)name delay:(float)delay;

/** creates an CCAnimation with a name, delay between frames and the CCSpriteFrames frames */
+(id) animationWithName:(NSString*)name delay:(float)delay frames:frame1,... NS_REQUIRES_NIL_TERMINATION;

/** initializes a CCAnimation with a name and delay between frames */
-(id) initWithName:(NSString*)name delay:(float)delay;

/** initializes a CCAnimation with a name, and the CCSpriteFrames */
-(id) initWithName:(NSString*)name delay:(float)delay firstFrame:(CCSpriteFrame*)frame vaList:(va_list) args;

/** adds a frame to a CCAnimation */
-(void) addFrameWithRect:(CGRect)rect;
@end