#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> values;
      for (int i = 0; i < nums.size(); i++) {
        values[nums[i]] = i;
      }

      // Debug
      std::cout << &values << " values = {";
      bool first = true;
      for (const auto& pair : values) {
        if (!first) {
          std::cout << ", ";
        }
        std::cout << "{" << pair.first << ": " << pair.second << "}";
        first = false;
      }
      std::cout << "}" << std::endl;
      // for (int i = 0; i < nums.size(); i++) {
      //   int value = nums[i];
      //   int diff = target - value;
      //   if (values.count(diff) > 0) {
      //     return vector<int>{i, values[diff]};
      //   }
      // }
      return vector<int>{};
    }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  Solution solution;
  vector<int> result = solution.twoSum(nums, 9);

  std::cout << "result = ";
  for (std::size_t i = 0; i < result.size(); ++i) {
    std::cout << (i > 0 ? ", " : "") << result[i];
  }
  std::cout << std::endl;
}
