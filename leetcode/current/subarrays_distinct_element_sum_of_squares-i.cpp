#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int sumCounts(vector<int> &nums) {
      for (std::size_t i = 0; i < nums.size(); ++i) {
        for (std::size_t j = i; j < nums.size(); ++j) {
          std::cout << this << " i = " << i << std::endl;
          std::cout << this << " j = " << j << std::endl;
        }
      }
      return 0;
    }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution solution;
  solution.sumCounts(nums);
}

