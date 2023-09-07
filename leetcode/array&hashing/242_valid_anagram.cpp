#include <string>
#include <unordered_map>

class Solution
{
public:
  bool isAnagram(std::string s, std::string t)
  {
    if (s.size() != t.size())
      return false;

    std::unordered_map<char, int> smap;
    std::unordered_map<char, int> tmap;

    for (int i = 0; i < s.size(); ++i)
    {
      smap[s[i]]++;
      tmap[t[i]]++;
    }

    for (int i = 0; i < smap.size(); i++)
    {
      if (smap[i] != tmap[i])
      {
        return false;
      }
    }

    return true;
  }
};
