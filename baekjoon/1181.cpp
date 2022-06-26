#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> words;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

bool compare(string s1, string s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	return s1.length() < s2.length();
}

int main(void)
{
	init();

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		words.push_back(word);
	}

	// remove duplicate elements!
	sort(words.begin(), words.end());
	words.erase(unique(words.begin(), words.end()), words.end());

	sort(words.begin(), words.end(), compare);
	
	for (auto word : words)
		cout << word << '\n';

	return 0;
}
