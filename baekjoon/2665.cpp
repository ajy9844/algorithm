#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

int n;
vector<string> map;

typedef struct _node {
	int y, x;
  int cost;
} Node;

int dy[] = { +1, -1, 0, 0 };
int dx[] = { 0, 0, +1, -1 };

struct compare {
	bool operator()(Node n1, Node n2) {
		return n1.cost > n2.cost;
	}
};

void init()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

int dijkstra(Node start, Node end)
{
  if (start.y == end.y && start.x == end.x)
    return 0;
  
  vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
  vector<vector<int>> visited(n, vector<int>(n, 0));
  priority_queue<Node, vector<Node>, compare> pq;

  dist[start.y][start.x] = 0;
  pq.push(start);

  while(!pq.empty()) {
    Node cur = pq.top();
    visited[cur.y][cur.x] = 1;
    pq.pop();
    
    for (int i = 0; i < 4; i++) {
      Node next = {cur.y + dy[i], cur.x + dx[i]};
      if (next.y >= 0 && next.y < n && next.x >= 0 && next.x < n && !visited[next.y][next.x]) {
        int cost = (map[next.y][next.x] == '0') ? 1 : 0;
        if (dist[next.y][next.x] > cur.cost + cost) {
          dist[next.y][next.x] = cur.cost + cost;
          next.cost = dist[next.y][next.x];
          pq.push(next);
        }
      } 
    }
  }
  /*
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dist[i][j];
    }
    cout << endl;
  }
  cout << endl;
  */
  return dist[end.y][end.x];
}

int main()
{
  init();

  cin >> n;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    map.push_back(row);
  }

  Node start = {0, 0, 0};
  Node end   = {n-1, n-1};

  cout << dijkstra(start, end);

  return 0;
}