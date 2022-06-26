#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
vector<int> graph[MAX];
vector<int> visited(MAX, 0);

void bfs(int start);

int main(void)
{
	int n, m; cin >> n >> m;
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v); // undirected graph
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			bfs(i);
		}
	}
	cout << cnt;

	return 0;
}

void bfs(int start)
{
	queue<int> q;

	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int node1 = q.front();
		q.pop();
		for (int i = 0; i < (int)graph[node1].size(); i++) {
			int node2 = graph[node1][i];
			if (!visited[node2]) {
				q.push(node2);
				visited[node2] = 1;
			}
		}
	}
}
