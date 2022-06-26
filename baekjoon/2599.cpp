#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int male[3];
int female[3];

int flag = 1;

void init();
void update(int mate[][3], int num[], vector<int>& diff);
void match(int mate[][3], int idx);
void calculate(int idx, int& fm1, int& fm2);

int main(void)
{
	/*
	 * for male students from the 'i'th elementary school,
	 * the diagonal elements represent whether all male students in the elementary school are paired,
	 * and the remaining elements represent the results of pairing.
	 */
	int mate[3][3] = { 0, };
	int max_num[3]; // maximum number of female students that male students can access to mate
	vector<int> diff(3);

	init();

	int n; cin >> n;
	for (int i = 0; i < 3; i++) {
		int m, fm; cin >> m >> fm;
		male[i] = m;
		female[i] = fm;
	}

	int t = 3;
	while (t--) {
		update(mate, max_num, diff);
		if (!flag) {
			cout << flag;
			return 0;
		}
		int min_idx = min_element(diff.begin(), diff.end()) - diff.begin();
		match(mate, min_idx);
	}

	cout << flag << '\n';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				continue;
			cout << mate[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void update(int mate[][3], int max_num[], vector<int>& diff)
{
	max_num[0] = female[1] + female[2];
	max_num[1] = female[0] + female[2];
	max_num[2] = female[0] + female[1];

	for (int i = 0; i < 3; i++) {
		if (mate[i][i])
			diff[i] = INT_MAX;
		else
			diff[i] = max_num[i] - male[i];
		if (diff[i] < 0) {
			flag = 0;
			break;
		}
	}
}

void match(int mate[][3], int idx)
{
	int fm1, fm2;

	switch (idx)
	{
	case 0:
		fm1 = female[1];
		fm2 = female[2];
		calculate(idx, fm1, fm2);

		mate[idx][1] = fm1;
		mate[idx][2] = fm2;
		female[1] -= fm1;
		female[2] -= fm2;
		break;

	case 1:
		fm1 = female[0];
		fm2 = female[2];
		calculate(idx, fm1, fm2);

		mate[idx][0] = fm1;
		mate[idx][2] = fm2;
		female[0] -= fm1;
		female[2] -= fm2;
		break;

	case 2:
		fm1 = female[0];
		fm2 = female[1];
		calculate(idx, fm1, fm2);

		mate[idx][0] = fm1;
		mate[idx][1] = fm2;
		female[0] -= fm1;
		female[1] -= fm2;
		break;
	}
	mate[idx][idx] = 1;
}

void calculate(int idx, int& fm1, int& fm2)
{
	if (fm1 - fm2 < 0) {
		if (fm1 - male[idx] < 0)
			fm2 = male[idx] - fm1;
		else {
			fm1 = male[idx];
			fm2 = 0;
		}
	}
	else {
		if (fm2 - male[idx] < 0)
			fm1 = male[idx] - fm2;
		else {
			fm2 = male[idx];
			fm1 = 0;
		}
	}
}
