#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis,
              stack<int> &st) {
  vis[node] = 1;
  for (auto it : adj[node]) {
    int v = it.first;
    if (!vis[v]) {
      topoSort(v, adj, vis, st);
    }
  }
  st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
  vector<pair<int, int>> adj[N];
  for (int i = 0; i < M; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    adj[u].push_back({v, wt});
  }

  // find the topoSort
  // int vis[N] = {0};
  vector<int> vis(N, 0);

  stack<int> st;
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      topoSort(i, adj, vis, st);
    }
  }

  // find the shortest path
  vector<int> dist(N, INT_MAX);
  dist[0] = 0;
  while (!st.empty()) {
    int node = st.top();
    st.pop();
    if (dist[node] != INT_MAX) {
      for (auto it : adj[node]) {
        int v = it.first;
        int wt = it.second;
        if (dist[node] + wt < dist[v]) {
          dist[v] = dist[node] + wt;
        }
      }
    }
  }
  return dist;
}

int main(int argc, char *argv[]) {
  int N = 6, M = 7;

  vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2},
                               {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};

  vector<int> ans = shortestPath(N, M, edges);

  for (int i = 0; i < ans.size(); i++) {

    cout << ans[i] << " ";
  }
  return 0;
}
