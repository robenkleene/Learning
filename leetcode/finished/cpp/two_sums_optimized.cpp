#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> values;
      for (int i = 0; i < nums.size(); i++) {
        int value = nums[i];
        int diff = target - value;
        if (values.count(diff) > 0) {
          return vector<int>{values[diff], i};
        }
        values[value] = i;
      }
      return vector<int>{};
    }
};

void dump(vector<int> arr) {
  for (std::size_t i = 0; i < arr.size(); ++i) {
    std::cout << (i > 0 ? ", " : "") << arr[i];
  }
  std::cout << std::endl;
}

void test(vector<int> nums, int target) {
  Solution solution;
  dump(nums);
  vector<int> result = solution.twoSum(nums, target);
  dump(result);
}

int main() {
  test({2, 7, 11, 15}, 9);
  std::cout << std::endl;
  test({3, 2, 4}, 6);
}
