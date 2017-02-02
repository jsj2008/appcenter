#import "ControlCenterUI.h"
#import "ControlCenterUIKit.h"
#import "MenuViewController.h"

@class ACAppIconCell;

@interface ACSearchButton : UIButton

@end

@interface ACIconButton : CCUIControlCenterButton

@end

@interface ACAppIconCell : UICollectionViewCell <CCUIControlCenterButtonDelegate>

@property (nonatomic, retain) NSString *appIdentifier;
@property (nonatomic, retain) UIImageView *imageView;
@property (nonatomic, retain) UILabel *titleLabel;
@property (nonatomic, retain) CCUIControlCenterButton *button;
@property (nonatomic, retain) UIActivityIndicatorView *loadingView;

- (void)configureForApplication:(NSString*)appIdentifier;
- (void)showActivity;
- (void)hideActivity;

@end

@interface ACAppSelectionGridViewController : UICollectionViewController

@end

@interface ACAppSelectionContainerView : UIView

@property (nonatomic, retain) ACIconButton *iconButton;
@property (nonatomic, retain) UILabel *titleLabel;
@property (nonatomic, retain) UIButton *searchButton;
@property (nonatomic, retain) UISearchBar *searchBar;

@end

@interface ACAppSelectionPageViewController : UIViewController <CCUIControlCenterPageContentProviding, UISearchBarDelegate, ACMenuViewControllerDelegate>

@property (nonatomic, retain) ACAppSelectionGridViewController *gridViewController;
@property (nonatomic, retain) ACMenuViewController *menuViewController;
@property (nonatomic, retain) ACAppSelectionContainerView *view;
@property (nonatomic, assign) ACAppIconCell *selectedCell;
@property (nonatomic, assign) BOOL searching;

- (void)beginSearching;
- (void)endSearching;
-(void)closeAllPagesButtonTapped;
-(void)closeAllAppsButtonTapped;

@end
