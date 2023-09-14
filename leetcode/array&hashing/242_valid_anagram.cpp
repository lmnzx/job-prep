#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;

    unordered_map<char, int> tmap;
    unordered_map<char, int> smap;

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
