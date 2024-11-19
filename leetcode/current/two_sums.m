#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface Solution : NSObject
+ (NSArray<NSNumber *> *)twoSumWithNums:(NSArray<NSNumber *> *)nums target:(NSInteger)target;
@end
NS_ASSUME_NONNULL_END

@implementation Solution
+ (NSArray<NSNumber *> *)twoSumWithNums:(NSArray<NSNumber *> *)nums target:(NSInteger)target {

    NSMutableDictionary<NSNumber *, NSNumber *> *values = [NSMutableDictionary dictionary];
    for (int i = 0; i < [nums count]; i++) {
        NSLog(@"%d", i);
    }
    return @[];
}
@end

int main() {
    NSLog(@"Hello, World!");
}
