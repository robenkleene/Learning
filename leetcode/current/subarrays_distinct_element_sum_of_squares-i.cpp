#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    int sumCounts(vector<int> &nums) {
      int sum = 0;

      for (std::size_t i = 0; i < nums.size(); ++i) {
        for (std::size_t j = i; j < nums.size(); ++j) {
          std::unordered_set<int> subset(nums.begin() + i, nums.begin() + j + 1);
          sum += std::pow(subset.size(), 2);
        }
      }
      return sum;
    }
};

int main() {
  vector<int> nums = {1, 2, 1};
  Solution solution;
  int result = solution.sumCounts(nums);
  std::cout << "result = " << result << std::endl;
}

