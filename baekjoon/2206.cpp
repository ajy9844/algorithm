#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAX = 1000;
int n, m;

string map[MAX];
int visited[MAX][MAX][2];

int dy[] = { +1, -1, 0, 0 };
int dx[] = { 0, 0, +1, -1 };

typedef struct _node {
  int y, x;
  int dist;
  int used;
} Node;

void init() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

int bfs(pair<int, int> start, pair<int, int> end) 
{
  if (start.first == end.first && start.second == end.second) {
    return 1;
  }
  
  queue<Node> q;
  Node node = { start.first, start.second, 1, 0 }, n_node;
  q.push(node);
  visited[node.y][node.x][0] = 1;
  visited[node.y][node.x][1] = 1;
 
  while (!q.empty()) {
    node = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      n_node = { node.y + dy[i], node.x + dx[i], node.dist + 1, node.used };
      if (n_node.y < n && n_node.y >= 0 && n_node.x < m && n_node.x >= 0) {
        if (n_node.y == end.first && n_node.x == end.second) {
            /*
            cout << endl;
            for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                cout << "(" + to_string(visited[i][j][0]) + "," + to_string(visited[i][j][1]) + ")";
              }
              cout << endl;
            }
            */
            return n_node.dist;
        }

        if (!visited[n_node.y][n_node.x][node.used]) {
          if (map[n_node.y][n_node.x] == '0') {
            q.push(n_node);
            visited[n_node.y][n_node.x][n_node.used] = 1;
          }
          else if (map[n_node.y][n_node.x] == '1' && !node.used) {
            n_node.used = 1;
            q.push(n_node);
            visited[n_node.y][n_node.x][n_node.used] = 1;
          }
        }
      }
    }
  }
  /*
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << "(" + to_string(visited[i][j][0]) + "," + to_string(visited[i][j][1]) + ")";
    }
    cout << endl;
  }
  */
  return -1;
}

int main() {
  init();
  cin >> n >> m;
  pair<int,int> start = {0, 0}, end = {n-1, m-1};

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    map[i] = s;
  }

  cout << bfs(start, end);
  
  return 0;
}
