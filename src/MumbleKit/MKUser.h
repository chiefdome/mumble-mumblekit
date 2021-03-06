/* Copyright (C) 2009-2010 Mikkel Krautz <mikkel@krautz.dk>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import <MumbleKit/MKServerModelObject.h>

typedef enum {
	MKTalkStatePassive = 0,
	MKTalkStateTalking,
	MKTalkStateWhispering,
	MKTalkStateShouting,
} MKTalkState;

@class MKChannel;

@interface MKUser : MKServerModelObject {
	BOOL         _muted;
	BOOL         _deafened;
	BOOL         _suppressed;
	BOOL         _localMuted;
	BOOL         _selfMuted;
	BOOL         _selfDeafened;
	BOOL         _friend;
	BOOL         _prioritySpeaker;
	BOOL         _recording;
	MKTalkState  _talkState;
	NSUInteger   _session;
	NSInteger    _userId;
	NSString     *_userHash;
	NSString     *_username;
	MKChannel    *_channel;
	NSString     *_comment;
	NSData       *_commentHash;
	NSData       *_texture;
	NSData       *_textureHash;
}

- (id) init;
- (void) dealloc;

- (NSInteger) userId;
- (NSUInteger) session;
- (NSString *) userName;
- (NSString *) userHash;
- (MKTalkState) talkState;
- (BOOL) isAuthenticated;
- (BOOL) isFriend;
- (BOOL) isMuted;
- (BOOL) isDeafened;
- (BOOL) isSuppressed;
- (BOOL) isLocalMuted;
- (BOOL) isSelfMuted;
- (BOOL) isSelfDeafened;
- (BOOL) isPrioritySpeaker;
- (BOOL) isRecording;
- (MKChannel *) channel;
- (NSData *) commentHash;
- (NSString *) comment;
- (NSData *) textureHash;
- (NSData *) texture;

@end
