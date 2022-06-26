#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 1001;
int prime_numbers[MAX] = {0,};

int main()
{
  int n, k;
  cin >> n >> k;

  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; i*j <= n; j++) {
      if (prime_numbers[i*j] != 0)
        continue;
      prime_numbers[i*j] = ++cnt;
      if (cnt == k) {
        cout << i*j << endl;
        break;
      }
    }
  }
  return 0;
}
