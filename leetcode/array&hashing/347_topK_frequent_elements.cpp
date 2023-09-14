#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    int n = nums.size();

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      m[nums[i]]++;
    }

    vector<vector<int>> bucket(n + 1);
    for (auto it = m.begin(); it != m.end(); it++)
    {
      bucket[it->second].push_back(it->first);
    }

    vector<int> result;

    for (int i = n; i >= 0; i--)
    {
      if (result.size() >= k)
      {
        break;
      }
      if (!bucket[i].empty())
      {
        result.insert(result.end(), bucket[i].begin(), bucket[i].end());
      }
    }

    return result;
  }
};