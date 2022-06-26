#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _point {
	int x, y;
} Point;

vector<Point> direct = { {-2, +1}, {-1, +2}, {+1, +2}, {+2, +1}, {+2, -1}, {+1, -2}, {-1, -2}, {-2, -1} };
int l; // l: length of a chessboard

int bfs(Point start, Point end);

int main(void)
{
	int t; cin >> t;
	Point start, end;

	while (t--) {
		cin >> l;
		cin >> start.x >> start.y;
		cin >> end.x >> end.y;

		int res;
		res = bfs(start, end);
		cout << res << endl;
	}

	return 0;
}

int bfs(Point start, Point end)
{
	vector<vector<int>> dist(l, vector<int>(l, -1));
	queue<Point> q;

	dist[start.x][start.y] = 0;
	q.push(start);

	while (!q.empty()) {
		Point p1 = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			Point p2 = { p1.x + direct[i].x, p1.y + direct[i].y };
			if ((p2.x >= 0 && p2.x < l) && (p2.y >= 0 && p2.y < l)) {
				if (dist[p2.x][p2.y] == -1) {
					q.push(p2);
					dist[p2.x][p2.y] = dist[p1.x][p1.y] + 1;
				}
			}
		}
		if (dist[end.x][end.y] != -1) {
			break;
		}
	}

	return dist[end.x][end.y];
}
