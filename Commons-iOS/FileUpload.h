//
//  FileUpload.h
//  Commons-iOS
//
//  Created by Brion on 1/25/13.
//  Copyright (c) 2013 Wikimedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <MapKit/MapKit.h>

#import "mwapi/MWApi.h"

@interface FileUpload : NSManagedObject

@property (nonatomic, retain) NSString * categories;
@property (nonatomic, retain) NSNumber * complete;
@property (nonatomic, retain) NSDate * created;
@property (nonatomic, retain) NSString * desc;
@property (nonatomic, retain) NSString * localFile;
@property (nonatomic, retain) NSString * fileType;
@property (nonatomic, retain) NSString * title;
@property (nonatomic, retain) NSNumber * progress;
@property (nonatomic, retain) NSString * source;
@property (nonatomic, retain) NSString * thumbnailURL;
@property (nonatomic, retain) NSNumber * fileSize;
@property (nonatomic, retain) NSString * license;
@property (nonatomic, retain) CLLocation * imageLocation;

@property (nonatomic, retain) NSNumber * fetchThumbnailProgress;

- (NSString *)prettySize;
- (MWPromise *)fetchThumbnailWithQueuePriority:(NSOperationQueuePriority)priority;
- (BOOL)isReadyForUpload;
- (NSArray *)categoryList;

- (void)addCategory:(NSString *)category;
- (void)removeCategory:(NSString *)category;

@end
