#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 101;
vector<vector<int>> graph(MAX, vector<int>(MAX, 0));
int n, m; // n: number of users, m: number of relations

int bfs(int start);

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int ans;
	int node = 1, min = INT_MAX;

	for (int i = 1; i <= n; i++) {
		ans = bfs(i);
		if (ans < min) {
			node = i;
			min = ans;
		}
	}
	cout << node;

	return 0;
}

int bfs(int start)
{
	vector<int> dist(n + 1, -1);
	queue<int> q;

	int res = 0;

	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (graph[node][i] && dist[i] == -1) {
				q.push(i);
				dist[i] = dist[node] + 1; // weight: 1
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		res += dist[i];
	}

	return res;
}
