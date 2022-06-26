#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct _edge {
	int node;
	int cost;
} Edge;

const int MAX = 801;
vector<Edge> graph[MAX];
int n, e;

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

int dijkstra(int start, int end, int& flag)
{
	if (start == end)
		return 0;

	vector<int> dist(n + 1, INT_MAX);
	priority_queue<Edge, vector<Edge>, compare> pq;

	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().node;
		int cur_cost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < (int)graph[cur].size(); i++) {
			int next = graph[cur][i].node;
			int next_cost = graph[cur][i].cost;

			if (dist[next] > cur_cost + next_cost) {
				dist[next] = cur_cost + next_cost;
				pq.push({ next, dist[next] });
			}
		}
	}

	if (dist[end] == INT_MAX) {
		flag = 1;
		return INT_MIN;
	}
	return dist[end];
}

int main(void)
{
	int start = 1, v1, v2, end;
	int cost1 = 0, cost2 = 0;
	int flag1 = 0, flag2 = 0;

	init();

	cin >> n >> e; end = n;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> v1 >> v2;

	// case1. start - v1 - v2 - end
	cost1 += dijkstra(start, v1, flag1);
	if (!flag1) {
		cost1 += dijkstra(v1, v2, flag1);
		if (!flag1) {
			cost1 += dijkstra(v2, end, flag1);
		}
	}

	// case2. start - v2 - v1 - end
	cost2 += dijkstra(start, v2, flag2);
	if (!flag2) {
		cost2 += dijkstra(v2, v1, flag2);
		if (!flag2) {
			cost2 += dijkstra(v1, end, flag2);
		}
	}

	if (!flag1 && !flag2)
		cout << min(cost1, cost2);
	else if (flag1 && flag2)
		cout << -1;
	else
		cout << max(cost1, cost2);

	return 0;
}
