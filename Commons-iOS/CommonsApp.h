//
//  CommonsApp.h
//  Commons-iOS
//
//  Created by Brion on 1/25/13.
//  Copyright (c) 2013 Wikimedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <MapKit/MapKit.h>
#import "FileUpload.h"
#import "Category.h"
#import "mwapi/MWApi.h"
#import "MWEventLogging/MWEventLogging.h"
#import "ThumbFetcher.h"
#import "SpeedGovernor.h"

@interface CommonsApp : NSObject

@property (strong, nonatomic) UIWindow *window;
@property (copy, nonatomic) NSString *username;
@property (copy, nonatomic) NSString *password;
@property (nonatomic) BOOL debugMode;

@property (strong, nonatomic) NSManagedObjectContext *context;
@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSFetchedResultsController *categoryResultsController;

@property (strong, nonatomic) MWApi *currentUploadOp;
@property (strong, nonatomic) MWEventLogging *eventLog;
@property (strong, nonatomic) ThumbFetcher *thumbFetcher;
@property (nonatomic) BOOL trackingEnabled;
@property (copy, nonatomic) NSString* defaultExternalBrowser;

@property (strong, nonatomic) NSOperationQueue *fetchDataURLQueue;
@property (strong, nonatomic) SpeedGovernor *speedGovernor;
@property (strong, nonatomic) FileUpload *recordToDelete;

@property (strong, nonatomic) NSArray *selectableLicenses;

+ (CommonsApp *)singleton;

- (void)initializeApp;
- (NSString *)version;
- (void)loadCredentials;
- (void)saveCredentials;
- (BOOL)processLaunchURL:(NSURL *)url;

- (NSString *)documentRootPath;
- (NSString *)filePath:(NSString *)fileName;
- (NSString *)thumbPath:(NSString *)fileName;
- (NSString *)potdPath:(NSString *)fileName;
- (NSString *)uniqueFilenameWithExtension:(NSString *)extension;

- (MWPromise *)loadImage:(NSString *)fileName fileType:(NSString *)fileType;
- (MWPromise *)fetchDataURL:(NSURL *)url withQueuePriority:(NSOperationQueuePriority)priority;
- (MWPromise *)fetchImageURL:(NSURL *)url;
- (MWPromise *)fetchWikiImage:(NSString *)title size:(CGSize)size withQueuePriority:(NSOperationQueuePriority)priority;

- (void)saveData;
- (void)fetchUploadRecords;
- (FileUpload *)createUploadRecord;
- (FileUpload *)firstUploadRecord;
- (NSArray *)recentCategories;
- (Category *)lookupCategory:(NSString *)name;
- (Category *)createCategory:(NSString *)name;
- (void)updateCategory:(NSString *)name;

- (MWApi *)startApi;
- (NSString *)wikiURLBase;
- (NSURL *)URLForWikiPage:(NSString *)title;
- (MWPromise *)beginUpload:(FileUpload *)record;
- (void)cancelCurrentUpload;

- (MWPromise *)prepareImage:(NSDictionary *)info from:(NSString *)source;
- (void)deleteUploadRecord:(FileUpload *)record;

- (MWPromise *)refreshHistoryWithFailureAlert:(BOOL)showFailureAlert;

- (NSString *)cleanupTitle:(NSString *)title;

- (NSString *)prettyDate:(NSDate *)date;
- (NSDate *)decodeDate:(NSString *)str;

- (void)log:(NSString *)schemaName event:(NSDictionary *)event;
- (void)log:(NSString *)schemaName event:(NSDictionary *)event override:(BOOL)override;
- (void)deleteAllRecords;

- (NSString *)desiredBrowserName;
- (void)openURLWithDefaultBrowser:(NSURL *)url;
- (CGSize)getFullSizedImageSize;
- (NSString *)getTrimmedString:(NSString *)string;

- (void)clearKeychainCredentials;

- (float)getStatusBarHeight;

- (NSString *)getBackButtonString;
- (UIBarButtonItem *)getBackButtonItemWithTarget:(id)target action:(SEL)action;

- (void)roundCorners:(UIRectCorner)corners ofView:(UIView *)view toRadius:(float)radius;
- (UILabel *)getRoundLabelForCharacter:(NSString *)character;

@end
