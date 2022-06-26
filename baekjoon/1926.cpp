#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 500;
int n, m;
vector<vector<int>> map(MAX, vector<int>(MAX, 0));

vector<int> pics;
int max_area = 0;

typedef struct _pair {
	int y, x;
} Pair;

int dy[] = { +1, -1, 0, 0 };
int dx[] = { 0, 0, +1, -1 };

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}

void bfs(Pair start)
{
	queue<Pair> q;
	q.push(start);
	// type of questions: size of area
	// using 'map' instead of 'visited' can shorten the execution time
	map[start.y][start.x] = 0;
	int pic_area = 1;

	while (!q.empty()) {
		Pair p1 = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Pair p2 = { p1.y + dy[i], p1.x + dx[i] };
			if ((p2.y >= 0 && p2.y < n) && (p2.x >= 0 && p2.x < m))
				if (map[p2.y][p2.x]) {
					q.push(p2);
					map[p2.y][p2.x] = 0;
					pic_area++;
				}
		}
	}
	pics.push_back(pic_area);
	if (max_area < pic_area)
		max_area = pic_area;
}

int main(void)
{
	init();
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j])
				bfs({ i, j });
		}
	}

	cout << pics.size() << '\n' << max_area;

	return 0;
}
