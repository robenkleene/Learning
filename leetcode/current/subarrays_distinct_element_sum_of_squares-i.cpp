#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int sumCounts(vector<int> &nums) {
      // Iterate through all subarrays
      for (std::size_t i = 0; i < nums.size(); ++i) {
        for (std::size_t j = i; j < nums.size(); ++j) {
          vector<int> subarray(nums.begin() + i, nums.begin() + j + 1);
          std::cout << "subarray = ";
          for (std::size_t i = 0; i < subarray.size(); ++i) {
              std::cout << (i > 0 ? ", " : "") << subarray[i];
          }
          std::cout << std::endl;
        }
      }
      return 0;
    }
};

int main() {
  vector<int> nums = {1, 2, 1};
  Solution solution;
  solution.sumCounts(nums);
}

