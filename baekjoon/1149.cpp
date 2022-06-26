#include <iostream>
#include <climits>
using namespace std;

const int MAX = 1000;
int cost[MAX][3]; // cost of painting red, green and blue in each house
int min_cost[MAX][3]; // minimum cost in level units

int n;
int min_sum = INT_MAX;

void dfs(int level, int pre_color, int sum)
{
	if (min_sum < sum)
		return;

	if (level == n) {
		if (min_sum > sum)
			min_sum = sum;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (i == pre_color)
			continue;

		if (min_cost[level][i] <= sum + cost[level][i])
			continue;
		else
			min_cost[level][i] = sum + cost[level][i];

		dfs(level + 1, i, min_cost[level][i]);
	}
}

int main(void)
{
	cin >> n;

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			int c; cin >> c;
			cost[i][j] = c;
			min_cost[i][j] = INT_MAX;
		}
	}
	for (i = 0; i < 3; i++) {
		min_cost[0][i] = cost[0][i];
	}

	for (i = 0; i < 3; i++) {
		dfs(1, i, min_cost[0][i]);
	}
	cout << min_sum;

	return 0;
}
