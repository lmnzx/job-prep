#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis) {
  vis[node] = 1;
  for (int i = 0; i < isConnected.size(); i++) {
    if (isConnected[node][i] && !vis[i]) {
      dfs(i, isConnected, vis);
    }
  }
}

int findCircleNum(vector<vector<int>> &isConnected) {
  int n = isConnected.size();
  vector<int> vis(n, 0);
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      count++;
      dfs(i, isConnected, vis);
    }
  }
  return count;
}

// space complexity:
// time complexity: O(N) + O(V + 2E)
int main(int argc, char *argv[]) {
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  cout << findCircleNum(isConnected) << endl;
  return 0;
}
