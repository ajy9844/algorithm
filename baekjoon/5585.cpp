#include <iostream>
#include <vector>
using namespace std;

vector<int> coin = { 500, 100, 50, 10, 5, 1 }; // descending order

int main(void)
{
	int n; cin >> n;
	n = 1000 - n;
	int res = 0;

	for (int i = 0; i < (int)coin.size(); i++) {
		res += n / coin[i];
		n = n % coin[i];
	}
	cout << res;

	return 0;
}
