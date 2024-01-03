#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] ||
      grid[i][j] == '0') {
    return;
  }
  vis[i][j] = 1;
  dfs(i + 1, j, grid, vis);
  dfs(i - 1, j, grid, vis);
  dfs(i, j + 1, grid, vis);
  dfs(i, j - 1, grid, vis);
}

int numIslands(vector<vector<char>> &grid) {
  int count = 0;
  vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (!vis[i][j] && grid[i][j] == '1') {
        count++;
        dfs(i, j, grid, vis);
      }
    }
  }

  return count;
}

int main(int argc, char *argv[]) {
  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};
  cout << numIslands(grid) << endl;

  return 0;
}
