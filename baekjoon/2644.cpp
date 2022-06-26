#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 101;
vector<int> graph[MAX];
int n, m; // n: number of people, m: number of parent-child relationships

int bfs(int start, int end);

int main(void)
{
	int start, end;
	cin >> n >> start >> end >> m;

	for (int i = 0; i < m; i++) {
		int x, y; // x: parent, y: child
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int res = 0;
	res = bfs(start, end);
	cout << res;

	return 0;
}

int bfs(int start, int end)
{
	vector<int> dist(n + 1, -1);
	queue<int> q;

	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int node1 = q.front();
		q.pop();
		for (int i = 0; i < (int)graph[node1].size(); i++) {
			int node2 = graph[node1][i];
			if (dist[node2] == -1) {
				q.push(node2);
				dist[node2] = dist[node1] + 1; // weight: 1
			}
		}
	}

	return dist[end];
}
