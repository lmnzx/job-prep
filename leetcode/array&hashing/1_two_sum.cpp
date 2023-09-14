#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
      int more = target - nums[i];
      if (map.find(more) != map.end())
      {
        return {map[more], i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};