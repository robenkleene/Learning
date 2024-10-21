#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, bool> values;
      for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
          int sum = nums[i] + nums[j];
          if (sum == target) {
            return vector<int>{i, j};
          }
        }
      }
      return vector<int>{};
    }
};
