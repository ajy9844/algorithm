#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 101;
int n, k;

int arr[2][MAX];

void init()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

int dp()
{
  vector<vector<int>> memo(n+1, vector<int>(k+1));

  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= k; w++) {
      int w_i = arr[0][i];
      int v_i = arr[1][i];
      
      if (w_i <= w) {
        memo[i][w] = max(v_i+memo[i-1][w-w_i], memo[i-1][w]);
      } else {
        memo[i][w] = memo[i-1][w];
      }
    }
  }
  return memo[n][k];
}

int main()
{
  init();
  
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int w, v; cin >> w >> v;
    arr[0][i] = w;
    arr[1][i] = v; 
  }

  int max_v = dp();
  cout << max_v;

  return 0;
}
