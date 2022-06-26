#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 250;
vector<string> map;
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));

int r, c;
int sheep = 0, wolf = 0;

typedef struct _pair {
	int y, x;
} Pair;

int dx[] = { +1, -1, 0, 0 };
int dy[] = { 0, 0, +1, -1 };

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}

void bfs(Pair start)
{
	// in one area
	int num_sheep = 0, num_wolf = 0;

	queue<Pair> q;
	q.push(start);
	visited[start.y][start.x] = 1;

	while (!q.empty()) {
		Pair p1 = q.front();
		q.pop();

		switch (map[p1.y][p1.x])
		{
		case '.':
			break;
		case 'o':
			num_sheep++;
			break;
		case 'v':
			num_wolf++;
			break;
		}

		for (int i = 0; i < 4; i++) {
			Pair p2 = { p1.y + dy[i], p1.x + dx[i] };
			if ((p2.y < r && p2.y >= 0) && (p2.x < c && p2.x >= 0))
				if (map[p2.y][p2.x] != '#' && !visited[p2.y][p2.x]) {
					q.push(p2);
					visited[p2.y][p2.x] = 1;
				}
		}
	}

	if (num_sheep > num_wolf)
		sheep += num_sheep;
	else
		wolf += num_wolf;
}

int main(void)
{
	init();

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string row;
		cin >> row;
		map.push_back(row);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((map[i][j] == 'o' || map[i][j] == 'v') && !visited[i][j])
				bfs({ i,j });
		}
	}

	cout << sheep << " " << wolf;

	return 0;
}
