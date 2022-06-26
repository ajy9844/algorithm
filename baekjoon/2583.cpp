#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100;
int m, n;

int map[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };

typedef struct _pair {
	int y, x;
} Pair;

int dy[] = { +1, -1, 0, 0 };
int dx[] = { 0, 0, +1, -1 };

vector<int> area;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void bfs(Pair start)
{
	queue<Pair> q;
	q.push(start);
	visited[start.y][start.x] = 1;
	int area_size = 1;

	while (!q.empty()) {
		Pair p1 = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Pair p2 = { p1.y + dy[i], p1.x + dx[i] };
			if ((p2.y >= 0 && p2.y < m) && (p2.x >= 0 && p2.x < n))
				if (!map[p2.y][p2.x] && !visited[p2.y][p2.x]) {
					q.push(p2);
					visited[p2.y][p2.x] = 1;
					area_size++;
				}
		}
	}
	area.push_back(area_size);
}

int main(void)
{
	init();
	
	int k; 
	cin >> m >> n >> k;
	while (k--) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for (int i = ly; i < ry; i++) {
			for (int j = lx; j < rx; j++) {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j] && !visited[i][j]) {
				bfs({ i, j });
			}
		}
	}

	cout << area.size() << '\n';
	sort(area.begin(), area.end());
	for (auto area_size : area) {
		cout << area_size << ' ';
	}

	return 0;
}
