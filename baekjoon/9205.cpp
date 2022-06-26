#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _pair {
	int x, y;
} Pair;

bool bfs(Pair start, Pair end, vector<Pair> store, int n);

int main(void)
{
	int t; cin >> t;

	while (t--) {
		vector<Pair> store;
		int n; cin >> n;
		Pair start, end;

		cin >> start.x >> start.y;
		for (int i = 0; i < n; i++) {
			Pair p;
			cin >> p.x >> p.y;
			store.push_back(p);
		}
		cin >> end.x >> end.y;

		if (bfs(start, end, store, n)) 
			cout << "happy" << endl;
		else
			cout << "sad" << endl; 
	}

	return 0;
}

bool bfs(Pair start, Pair end, vector<Pair> store, int n)
{
	vector<int> visited(n, 0);
	queue<Pair> q;
	q.push(start);

	int distance;
	bool arrival = false;

	while (!q.empty()) {
		Pair p1 = q.front();
		q.pop();
		distance = abs(end.x - p1.x) + abs(end.y - p1.y);
		if (distance <= 50 * 20) {
			arrival = true;
			break;
		}

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				Pair p2 = store[i];
				distance = abs(p2.x - p1.x) + abs(p2.y - p1.y);
				if (distance <= 50 * 20) {
					q.push(p2);
					visited[i] = 1;
				}
			}
		}
	}

	if (arrival) { return true; }
	else { return false; }
}
