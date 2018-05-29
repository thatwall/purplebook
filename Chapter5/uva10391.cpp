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
#include <iterator>
#include <deque>
#include <sstream>
using namespace std;

set<string> strs;
vector<string> res;

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	string str;
	while (cin >> str) {
		strs.insert(str);
	}
	for (auto i : strs) {
		for (int j = 1; j < i.size(); j++) {
			auto pre = i.substr(0, j), post = i.substr(j);
			if (strs.find(pre) != strs.end() && strs.find(post) != strs.end()) {
				cout << i << endl;
				break;
			}
		}
	}
	/*sort(res.begin(), res.end());
	for (auto i : res) {
		cout << i << endl;
	}*/
	return 0;
}
