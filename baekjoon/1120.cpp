#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main(void)
{
	string a, b; cin >> a >> b;
	int min = INT_MAX;

	for (int i = 0; i <= b.length() - a.length(); i++) {
		int j = i, dist = 0;
		for (int k = 0; k < a.length(); k++) {
			if (a[k] != b[j]) {
				dist++;
			}
			j++;
		}
		if (min > dist) {
			min = dist;
		}
	}

	cout << min;

	return 0;
}
