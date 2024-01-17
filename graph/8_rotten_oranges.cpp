#include <queue>
#include <utility>
#include <vector>

using namespace std;

  int orangesrotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited = grid;
    // making queue in which we will fill rotten oranges
    queue<pair<int, int>> q;
    int countfreshorange = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] == 2) {
          q.push({i, j});
        }
        if (visited[i][j] == 1) {
          countfreshorange++;
        }
      }
    }
    // q.empty() means there is no rotten orange in the grid and
    // countfreshorange = 0 means we will rotten the freshoranges in 0 mins
    if (countfreshorange == 0)
      return 0;
    if (q.empty())
      return -1;

    int minutes = -1;
    // we will cover four directions i.e. up, down, left, right
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dirs) {
          int i = x + dx;
          int j = y + dy;
          if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
            visited[i][j] = 2;
            countfreshorange--;
            q.push({i, j});
          }
        }
      }
      minutes++;
    }

    if (countfreshorange == 0)
      return minutes;
    return -1;
  }

