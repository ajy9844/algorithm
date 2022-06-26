#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 101;
int n, m;

vector<vector<int>> graph(MAX, vector<int>(MAX, 0));

void init() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

void bfs(int v, int& cnt) 
{
  vector<int> visited(n + 1, 0);
  queue<int> q;

  q.push(v);
  visited[v] = 1;

  while(!q.empty()) {
    int node = q.front();
    q.pop();
    cnt++;

    for (int i = 1; i <= n; i++) {
      if (graph[node][i] && !visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
}

int main() 
{
  init();
  cin >> n >> m;
  int v = 1;
  int cnt = -1;

  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  bfs(v, cnt);
  cout << cnt;

  return 0;
}
