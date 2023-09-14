#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < strs.size(); i++)
    {
      string key = getKey(strs[i]);
      map[key].push_back(strs[i]);
    }

    vector<vector<string>> result;
    for (auto it = map.begin(); it != map.end(); it++)
    {
      result.push_back(it->second);
    }
    return result;
  }

private:
  string getKey(string str)
  {
    vector<int> count(26);
    for (int i = 0; i < str.size(); i++)
    {
      count[str[i] - 'a']++;
    }

    string key;
    for (int i = 0; i < count.size(); i++)
    {
      key.append(to_string(count[i]) + '#');
    }
    return key;
  }
};