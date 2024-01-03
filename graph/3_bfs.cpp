// BFS: Breadth First Search
// level order traversal

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> bfs(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);
  queue<int> q;
  vis[0] = 1;
  // push the initial starting node
  q.push(0);
  vector<int> bfs;

  // iterate until the queue is empty
  while (!q.empty()) {
    // pop the front node from the queue
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    // traverse its neighbours
    for (auto it : adj[node]) {
      // if a neighbour is not visited
      if (!vis[it]) {
        // mark it visited
        vis[it] = 1;
        // push it into the queue
        q.push(it);
      }
    }
  }
  return bfs;
}

int main(int argc, char *argv[]) { 
  vector<int> adj[6];
  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[1].push_back(2);
  adj[2].push_back(1);
  adj[1].push_back(3);
  adj[3].push_back(1);
  adj[0].push_back(4);
  adj[4].push_back(0);

  vector<int> res = bfs(5, adj);
  for (auto it : res) {
    cout << it << " ";
  }
  return 0; 
}

