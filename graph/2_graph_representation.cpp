#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m; // n: number of vertices, m: number of edges 
  cin >> n >> m;
  int adj[n+1][n+1]; // adjacency matrix
  for (int i = 0; i < m; i++) {
    int u, v; // u: source vertex, v: destination vertex
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  // time complexity: O(n)
  // space complexity: O(n^2)

  // adjacency list
  int nl, ml;
  cin >> nl >> ml;
  vector<int> adjl[nl+1]; // array of vectors 
  for (int i = 0; i < ml; i++) {
    int u, v;
    cin >> u >> v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }
  // time complexity: O(n)
  // space complexity: O(2m) for undirected graph
  //                   O(m) for directed graph
  return 0;
}
