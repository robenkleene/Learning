#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int sumCounts(vector<int> &nums) {
      int sum = 0;

      for (std::size_t i = 0; i < nums.size(); ++i) {
        for (std::size_t j = i; j < nums.size(); ++j) {
          std::unordered_set<int> subset(nums.begin() + i, nums.begin() + j + 1);
          sum += subset.size();

          // Debug code
          std::cout << "subset = ";
          for (auto it = subset.begin(); it != subset.end(); ++it) {
            if (it != subset.begin()) {
              std::cout << ", ";
            }
            std::cout << *it;
          }
          std::cout << std::endl;
          //

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

