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
set<string> dict;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	string word;
	char c;
	while ((c = getchar()) != EOF) {
		if (!isalpha(c)) {
			if (!word.empty()) {
				dict.insert(word);
			}
			word.clear();
			continue;
		}
		if ('A' <= c && c <= 'Z') {
			c = c - 'A' + 'a';
		}
		word += c;
	}
	if (!word.empty()) {
		dict.insert(word);
	}
	for (auto i = dict.begin(); i != dict.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}
