#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<string> map;
int n, m;

typedef struct _edge {
	int ny, nx;
	int cost;
} Edge;

int dy[] = { +1, -1, 0, 0 };
int dx[] = { 0, 0, +1, -1 };

struct compare {
	bool operator()(Edge e1, Edge e2) {
		return e1.cost > e2.cost;
	}
};

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}

int dijkstra(Edge start, Edge end)
{
	vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
	vector<vector<int>> visited(n, vector<int>(m, 0));
	priority_queue<Edge, vector<Edge>, compare> pq;

	dist[start.ny][start.nx] = 0;
	visited[start.ny][start.nx] = 1;
	pq.push(start);

	while (!pq.empty())
	{
		Edge cur = pq.top();
		visited[cur.ny][cur.nx] = 1;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			Edge next = { cur.ny + dy[i], cur.nx + dx[i] };
			if ((next.ny >= 0 && next.ny < n) && (next.nx >= 0 && next.nx < m) && !visited[next.ny][next.nx]) {
				int next_cost = map[next.ny][next.nx] - '0';
				if (dist[next.ny][next.nx] > cur.cost + next_cost) {
					dist[next.ny][next.nx] = cur.cost + next_cost;
					next.cost = dist[next.ny][next.nx];
					pq.push(next);
				}
			}	
		}
	}
	return dist[end.ny][end.nx];
}

int main(void)
{
	init();

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		map.push_back(row);
	}

	Edge start = { 0, 0, 0 };
	Edge end = { n - 1, m - 1 };

	cout << dijkstra(start, end);

	return 0;
}
