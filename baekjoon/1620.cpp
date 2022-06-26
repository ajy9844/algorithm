#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

const int MAX = 100001;
string idxs[MAX];
map<string, int> names;
vector<string> answers;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

bool is_digit(string str)
{
	return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}

int main(void)
{
	init();

	int n, m; 
	cin >> n >> m;

	for (int idx = 1; idx <= n; idx++) {
		string name;
		cin >> name;
		idxs[idx] = name;
		names.insert(make_pair(name, idx));
	}

	for (int i = 0; i < m; i++) {
		string question;
		cin >> question;

		if (is_digit(question)) {
			int idx = stoi(question);
			answers.push_back(idxs[idx]);
		}
		else {
			string name = question;
			answers.push_back(to_string(names[name]));
		}
	}

	for (auto answer : answers) {
		cout << answer << '\n';
	}

	return 0;
}
