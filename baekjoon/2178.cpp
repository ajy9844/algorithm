#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 100;
int n, m;

vector<string> map;
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
pair<int, int> path[MAX][MAX];

typedef struct _node {
	int y, x;
	int count;
} Node;

int dy[] = { +1, -1, 0, 0 };
int dx[] = { 0, 0, +1, -1 };

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void bfs(Node start, Node end)
{
	queue<Node> q;
	q.push(start);
	visited[start.y][start.x] = 1;

	while (!q.empty())
	{
		Node n1 = q.front();
		q.pop();

		if (n1.y == end.y && n1.x == end.x) {
			cout << n1.count << '\n';
		}

		for (int i = 0; i < 4; i++) {
			Node n2 = { n1.y + dy[i], n1.x + dx[i], n1.count + 1 };
			if ((n2.y >= 0 && n2.y < n) && (n2.x >= 0 && n2.x < m))
				if (map[n2.y][n2.x] == '1' && !visited[n2.y][n2.x]) {
					q.push(n2);
					visited[n2.y][n2.x] = 1;
					path[n2.y][n2.x] = { n1.y, n1.x };
				}
		}
	}
}

int main(void)
{	
	init();
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		map.push_back(row);
	}

	bfs({ 0, 0, 1 }, { n - 1, m - 1, -1 });

	// print the path!
	stack<pair<int, int>> s;
	int cury = n - 1, curx = m - 1;
	int nexty, nextx;

	while (true) {
		s.push(make_pair(cury, curx));
		if (cury == 0 && curx == 0)
			break;
		nexty = path[cury][curx].first;
		nextx = path[cury][curx].second;
		cury = nexty;
		curx = nextx;
	}
	while (!s.empty()) {
		printf("(%d,%d) ", s.top().first + 1, s.top().second + 1);
		s.pop();
	}

	return 0;
}
