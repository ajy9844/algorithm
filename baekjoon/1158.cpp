#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int n, k; cin >> n >> k;
	vector<int> visited(n, 0);

	int i = k - 1, size = n;
	string res = "<";

	while (size) {
		res.append(to_string(i + 1));
		if (size == 1) {
			res.append(">");
			break;
		}
		else {
			res.append(", ");
		}
		visited[i] = 1;
		size--;

		int cnt = 0;
		while (cnt < k) {
			i = (i + 1) % n;
			if (!visited[i]) {
				if (size == 1) { break; } // quickly!
				cnt++;
			}
		}
	}

	cout << res;

	return 0;
}
