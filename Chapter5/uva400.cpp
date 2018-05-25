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
using namespace std;
vector<string> s;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n;
	while (cin >> n) {
		s.clear();
		string str;
		int m = 0;
		for (int i = 0; i < n; i++) {
			cin >> str;
			if (m < str.size()) {
				m = str.size();
			}
			s.push_back(str);
		}
		sort(s.begin(), s.end());
		int c = (60 - m) / (m + 2) + 1;
		int r = ceil((double)n / c);
		for (int i = 0; i < 60; i++) {
			cout << '-';
		}
		cout << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int idx = j * r + i;
				if (idx < s.size()) {
					if (j) {
						cout << "  ";
					}
					cout << setw(m) << left << s[idx];
				}
			}
			cout << endl;
		}
	}
	return 0;
}
