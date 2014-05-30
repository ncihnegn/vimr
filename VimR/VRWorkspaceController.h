/**
 * Tae Won Ha — @hataewon
 *
 * http://taewon.de
 * http://qvacua.com
 *
 * See LICENSE
 */

#import <Cocoa/Cocoa.h>
#import <MacVimFramework/MacVimFramework.h>


extern NSString *const qVimArgFileNamesToOpen;
extern NSString *const qVimArgOpenFilesLayout;

@class VRMainWindowController;
@class VRFileItemManager;
@class VROpenQuicklyWindowController;

@interface VRWorkspaceController : NSObject <MMVimManagerDelegateProtocol>

@property (nonatomic, weak) VRFileItemManager *fileItemManager;
@property (nonatomic, weak) VROpenQuicklyWindowController *openQuicklyWindowController;
@property (nonatomic, weak) NSUserDefaults *userDefaults;
@property (nonatomic, weak) NSNotificationCenter *notificationCenter;
@property (nonatomic, weak) MMVimManager *vimManager;

@property (nonatomic, readonly) NSArray *workspaces;

#pragma mark Public
- (void)newWorkspace;
- (void)openFilesInNewWorkspace:(NSArray *)fileUrls;
- (void)cleanUp;
- (BOOL)hasDirtyBuffers;

#pragma mark NSObject
- (id)init;

#pragma mark MMVimManagerDelegate
- (void)manager:(MMVimManager *)manager vimControllerCreated:(MMVimController *)vimController;
- (void)manager:(MMVimManager *)manager vimControllerRemovedWithControllerId:(unsigned int)controllerId pid:(int)pid;
- (NSMenuItem *)menuItemTemplateForManager:(MMVimManager *)manager;

- (void)selectBufferWithUrl:(NSURL *)url;
@end
