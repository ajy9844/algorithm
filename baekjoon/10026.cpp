#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 100;
int n;

string map[MAX];

typedef struct _pair {
  int y, x;
} Pair;

int dy[] = { +1, -1, 0, 0 };
int dx[] = { 0, 0, +1, -1 };

void init()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

void bfs(int (*visited)[MAX], int flag, Pair p)
{
  queue<Pair> q;
  q.push(p);
  visited[p.y][p.x] = 1;
  char init_v = map[p.y][p.x];

  while (!q.empty()) {
    Pair p1 = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      Pair p2 = { p1.y + dy[i], p1.x + dx[i] };
      if (p2.y < n && p2.y >= 0 && p2.x < n && p2.x >= 0) {
        if (visited[p2.y][p2.x] == 0) {
          if (flag == 0) {
            if (map[p2.y][p2.x] == init_v) {
              q.push(p2);
              visited[p2.y][p2.x] = 1;
            }
          } 
          else {
            if (init_v == 'R' || init_v == 'G') {
              if (map[p2.y][p2.x] == 'R' || map[p2.y][p2.x] == 'G') {
                q.push(p2);
                visited[p2.y][p2.x] = 1;
              }
            } else {
              if (map[p2.y][p2.x] == init_v) {
                q.push(p2);
                visited[p2.y][p2.x] = 1;
              }
            }
          }
        }
      }
    }
  }
}

int count(int flag)
{
  int visited[MAX][MAX] = {0,};
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j] == 0) {
        bfs(visited, flag, {i, j});
        cnt++;
      }
    }
  }
  return cnt;
}

int main()
{
  init();
  cin >> n;
  int res1, res2;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    map[i] = s;
  }
  
  res1 = count(0); // x
  res2 = count(1); // o

  cout << res1 << " " << res2;

  return 0;
}
