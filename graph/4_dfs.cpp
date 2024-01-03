// DFS: Depth First Search

#include <iostream>
#include <vector>

using namespace std;

// for undirected graph time complexity: O(V) + O(2E)
// for directed graph time complexity: O(V) + O(E)
// space complexity: O(V) + O(V) + O(V) + O(V) = O(V)
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
  // mark the node as visited
  vis[node] = 1;
  ls.push_back(node); // add the node to the list
  // traverse its neighbours
  for (auto it : adj[node]) {
    if (!vis[it]) {
      dfs(it, adj, vis, ls); // call dfs for the unvisited neighbour
    }
  }
}

vector<int> dfsTraversal(int V, vector<int> adj[]) {
  vector<int> ls;
  vector<int> vis(V, 0);
  dfs(0, adj, vis, ls);
  return ls;
}

int main(int argc, char *argv[]) {
  vector<int> adj[5];
  adj[0].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(4);
  adj[4].push_back(2);
  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[0].push_back(3);
  adj[3].push_back(0);

  vector<int> res = dfsTraversal(6, adj);
  for (auto it : res) {
    cout << it << " ";
  }
  return 0;
}
