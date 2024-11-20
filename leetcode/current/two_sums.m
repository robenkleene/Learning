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

void test(NSArray<NSNumber *> *nums, NSInteger target) {
    NSLog(@"nums = %@", nums);
    NSArray<NSNumber *> *result = [Solution twoSumWithNums:nums target:target];
    NSLog(@"result = %@", result);
}

int main() {
    test(@[@2, @7, @11, @15], 9);
    NSLog(@"");
    test(@[@3, @2, @4], 6);
}
