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
const int maxn = 10000 + 5;
const int maxm = 10 + 5;
int table[maxn][maxm];
int aloc = -1;
map<string, int> ID;
map<pair<int, int>, int> tbl;
int id(string str) {
	if (!ID.count(str)) {
		ID[str] = ++aloc;
	}
	return ID[str];
}

void solve(int rows, int cols) {
	for (int x = 1; x <= cols; x++) {
		for (int y = x+1; y <= cols; y++) {
			tbl.clear();
			for (int r = 1; r <= rows; r++) {
				if (tbl.count(make_pair(table[r][x],table[r][y]))) {
					cout << "NO" << endl;
					cout << tbl[make_pair(table[r][x], table[r][y])];
					cout << ' ' << r << endl;
					cout << x << ' ' << y << endl;
					return;
				} else {
					tbl[make_pair(table[r][x], table[r][y])] = r;
				}
			}
		}
	}
	cout << "YES" << endl;
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n, m;
	while (cin >> n >> m) {
		getchar(); //
		string str;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m-1; j++) {
				getline(cin, str, ',');
				table[i][j] = id(str);
			}
			getline(cin, str);
			table[i][m] = id(str);
		}
		solve(n, m);
	}
	return 0;
}
