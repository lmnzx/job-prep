#include <iostream>
#include <vector>

using namespace std;

void dfs(int r, int c, vector<vector<int>> &ans, int color, int b) {
  if (r < 0 || c < 0 || r >= ans.size() || c >= ans[0].size() ||
      ans[r][c] != b || ans[r][c] == color) {
    return;
  }
  ans[r][c] = color;
  dfs(r + 1, c, ans, color, b);
  dfs(r - 1, c, ans, color, b);
  dfs(r, c + 1, ans, color, b);
  dfs(r, c - 1, ans, color, b);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color) {
  int b = image[sr][sc];
  vector<vector<int>> ans = image;
  dfs(sr, sc, ans, color, b);
  return ans;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  int sr = 1, sc = 1, newColor = 2;
  vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
  for (auto i : ans) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
