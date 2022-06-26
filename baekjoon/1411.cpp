#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> words;
vector<string> applied_words;

void apply_form(int n);

int main(void)
{
    int n; cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        words.push_back(str);
    }

    apply_form(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!applied_words[i].compare(applied_words[j])) {
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}

void apply_form(int n)
{
    for (int i = 0; i < n; i++) {
        vector<char> char_set;
        vector<char>::iterator iter;

        string str = words[i];
        char key; int value;
        string applied_word = "";

        for (int j = 0; j < (int)str.length(); j++) {
            key = str[j];
            iter = find(char_set.begin(), char_set.end(), key);

            if (iter != char_set.end()) {
                value = iter - char_set.begin();
            }
            else {
                char_set.push_back(key);
                value = char_set.size() - 1;
            }

            applied_word += to_string(value);
        }
        applied_words.push_back(applied_word);
    }
    /*
    for (int i = 0; i < (int)applied_words.size(); i++) {
        cout << applied_words[i] << endl;
    }
    */
}
