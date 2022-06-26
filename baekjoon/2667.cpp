#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 25;
int n;

string map[MAX];
int visited[MAX][MAX];

typedef struct _pair {
  int y, x;
} Pair;

int dy[] = { +1, -1, 0, 0 };
int dx[] = { 0, 0, +1, -1 };

void init()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
}

void dfs(Pair cp, int& depth)
{
  depth += 1;
  //visited[cp.y][cp.x] = depth;
  visited[cp.y][cp.x] = 1;

  for (int i = 0; i < 4; i++) {
    Pair np = { cp.y + dy[i], cp.x + dx[i] };
    if (np.y < n && np.y >= 0 && np.x < n && np.x >= 0) {
      if (map[np.y][np.x] == '1' && !visited[np.y][np.x]) {
        dfs(np, depth);
      }
    }
  }
}

void count(vector<int>& result) 
{
  int depth = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == '1' && !visited[i][j]) {
        dfs({i, j}, depth);
        result.push_back(depth);
        /*
        cout << endl;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            cout << visited[i][j];
          }
          cout << endl;
        }
        */
        depth = 0;
      }
    }
  }
  sort(result.begin(), result.end());
}

int main()
{
  init();
  cin >> n;
  vector<int> result;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    map[i] = s;
  }

  count(result);

  cout << result.size() << endl;
  for (int i = 0;  i < result.size(); i++) {
    if (i == result.size() - 1) {
      cout << result[i] << " ";
      break;
    }
    cout << result[i] << endl;
  }

  return 0;
}
