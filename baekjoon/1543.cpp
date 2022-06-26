#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string doc, word;
	int count = 0;

	// enter a string containing spaces
	getline(cin, doc);
	getline(cin, word);

	for (int i = 0; i < (int)doc.length();) {
		bool find = true;
		for (int j = 0; j < (int)word.length(); j++) {
			if (doc[i + j] != word[j]) {
				find = false;
				break;
			}
		}
		if (find) {
			count++;
			i += (int)word.length();
		}
		else {
			i++;
		}
	}

	cout << count;

	return 0;
}
