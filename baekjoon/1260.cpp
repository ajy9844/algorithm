#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int MAX = 1001;
int n, m;

vector<vector<int>> graph(MAX, vector<int>(MAX, 0));
vector<int> visited(MAX, 0); // used in dfs

void dfs(int start);
void bfs(int start);

int main(void)
{
	int start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	dfs(start); cout << endl;
	bfs(start);

	return 0;
}

void dfs(int start)
{
	// use recursive
	visited[start] = 1;
	cout << start << " ";

	for (int i = 1; i <= n; i++) {
		if (graph[start][i] && !visited[i]) {
			dfs(i);
		}
	}
}

/*
void dfs(int start)
{
	// use stack
	stack<int> s;

	s.push(start);
	visited[start] = 1;
	cout << start << " ";

	while (!s.empty()) {
		int node = s.top();
		s.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[node][i] && !visited[i]) {
				visited[i] = 1;
				cout << i << " ";

				s.push(node);
				s.push(i);
				break;
			}
		}
	}
}
*/

void bfs(int start)
{
	vector<int> visited(n + 1, 0); // used in bfs
	queue<int> q;

	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";

		for (int i = 1; i <= n; i++) {
			if (graph[node][i] && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}
