#include <iterator>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> kWeakestRows (vector<vector<int>>& mat, int k){
    vector<pair<int, int>> rowStrengths;

    for (int i=0; i<mat.size(); i++) {
    int s = accumulate(mat[i].begin(), mat[i].end(), 0);
      rowStrengths.push_back({s, i});
     }
    vector<int> res;
    sort(rowStrengths.begin(), rowStrengths.end());
    for (int i=0; i < k; i++) {
      res.push_back(rowStrengths[i].second); 
    }
  return res;
  }

};
