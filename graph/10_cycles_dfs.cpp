#include <iostream>
#include <vector>

using namespace std;

bool detect(int src, int parent, vector<int> &vis, vector<int> adj[]) {
  vis[src] = 1;
  for (auto adjN : adj[src]) {
    if (!vis[adjN]) {
      if (detect(adjN, src, vis, adj) == true)
        return true;
    } else if (adjN != parent)
      return true;
  }
  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      if (detect(i, -1, vis, adj) == true)
        return true;
    }
  }
  return false;
}

int main() {
  vector<int> adj[8] = {{},  {2, 3}, {1, 5}, {4, 1, 6},
                        {3}, {2, 7}, {3, 7}, {5, 6}};
  cout << isCycle(8, adj) << endl;
  return 0;
}
