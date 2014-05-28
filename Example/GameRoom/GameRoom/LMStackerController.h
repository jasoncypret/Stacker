//
//  LMStackerController.h
//
//  Created by @LokiMeyburg
//  MIT Licence
//

#import <UIKit/UIKit.h>
#import "LMStackerWebViewController.h"
#import "LMStackerBrowserController.h"

// Create delegate so we can call parent navigation
@protocol LMStackerControllerDelegate <UINavigationControllerDelegate>
- (void)showBrowserView:(NSString*)browserURL;
@end

@interface LMStackerController : UINavigationController <LMStackerWebViewControllerDelegate, UIActionSheetDelegate> {
    LMStackerBrowserController *browserNavController;
    NSString *browserViewURL;
}


// Initializers
- (id)initWithURL:(NSString*)url;

// Delegate property
@property (nonatomic,assign) id <LMStackerControllerDelegate, UINavigationControllerDelegate> delegate;

// Public Methods
- (void) pushNewPage:(NSString*)pageURL;
- (void) replacePage:(NSString*)pageURL;
- (void) refreshPage;
- (void) popPage;
- (void) clearStack;


// Properties
@property UIWebView *myWebView;
@property NSString *pageURL;
@property UIImage *rootPageTitleImage;
@property NSString *stackerBackgroundColor;
@property BOOL statusBarLight;
@property NSDictionary *buttonHandlers;
@property NSDictionary *customURLHandlers;
@property NSString *refreshSpinnerColor;
@property NSString *loadingSpinnerColor;


@end