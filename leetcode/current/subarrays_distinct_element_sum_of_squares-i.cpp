#include <iostream>
#include <vector>

using namespace std;

int main() {
  std::cout << "Hello, World!" << std::endl;
}

class Solution {
  public:
    int sumCounts(vector<int> &nums) {
      for (std::size_t i = 0; i < nums.size(); ++i) {
        for (std::size_t j = 0; j < nums.size(); ++j) {
          std::cout << nums[j] << std::endl;
        }
      }
      return 0;
    }
};
