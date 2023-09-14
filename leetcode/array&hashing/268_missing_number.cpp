#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int sum = accumulate(nums.begin(), nums.end(), 0, [](int a, int b)
                         { return a + b; });

    int expectedSum = (nums.size() * (nums.size() + 1)) / 2;

    return expectedSum - sum;
  }
};