//
//  DBAttachmentPickerController.h
//  DBAttachmentPickerController
//
//  Created by Denis Bogatyrev on 14.03.16.
//
//  The MIT License (MIT)
//  Copyright (c) 2016 Denis Bogatyrev.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>

typedef NS_OPTIONS(NSUInteger, DBAttachmentMediaType) {
    DBAttachmentMediaTypeImage = (1 << 0),
    DBAttachmentMediaTypeVideo = (1 << 1),
    DBAttachmentMediaTypeOther = (1 << 2),
};

UIKIT_EXTERN const DBAttachmentMediaType DBAttachmentMediaTypeAllMask;

NS_ASSUME_NONNULL_BEGIN
@class DBAttachmentPickerController, DBAttachment;
@protocol DBAttachmentPickerControllerDelegate <NSObject>

@optional
- (void)DBAttachmentPickerController:(DBAttachmentPickerController *)controller didFinishPickingAttachmentArray:(NSArray<DBAttachment *> *)attachmentArray;
- (void)DBAttachmentPickerControllerDidCancel:(DBAttachmentPickerController *)controller;

@end

@interface DBAttachmentPickerController : NSObject

@property (weak, nonatomic) id<DBAttachmentPickerControllerDelegate> delegate;
@property (assign, nonatomic, readonly) DBAttachmentMediaType mediaType;

- (instancetype)initWithMediaType:(DBAttachmentMediaType)mediaType;
- (void)presentAttachmentPickerOnViewController:(UIViewController *)initialViewController;

@end
NS_ASSUME_NONNULL_END