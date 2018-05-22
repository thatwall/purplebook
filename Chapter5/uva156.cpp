#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;
map<string, vector<string>> dict;
set<string> sing;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	string word, key;
	char c;
	while ((c = getchar()) != '#') {
		if (!isalpha(c)) {
			if (!key.empty()) {
				sort(key.begin(), key.end());
			}
			if (!word.empty()) {
				dict[key].push_back(word);
			}
			key.clear();
			word.clear();
			continue;
		}
		word += c;
		if ('A' <= c && c <= 'Z') {
			c = c - 'A' + 'a';
		}
		key += c;
	}
	if (!key.empty()) {
		sort(key.begin(), key.end());
	}
	if (!word.empty()) {
		dict[key].push_back(word);
	}
	for (auto i = dict.begin(); i != dict.end(); i++) {
		if (i->second.size() == 1) {
			sing.insert(i->second.front());
		}
	}
	for (auto i = sing.begin(); i != sing.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}
