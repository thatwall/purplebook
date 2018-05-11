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
using namespace std;

struct student {
	int a, b, c;
};

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n;
	int k = 0;
	while (cin >> n && n) {
		vector<student> stus(n);
		vector<int> cur(n);
		for (int i = 0; i < n; i++) {
			cin >> stus[i].a >> stus[i].b >> stus[i].c;
			cur[i] = stus[i].c;
		}
		int res = 0;
		bool flag = false;
		for (int i = 2; ; i++) {
			int slp = 0;
			for (int j = 0; j < n; j++) {
				if (cur[j] > stus[j].a) {
					slp++;
				}
			}
			if (!slp) {
				flag = true;
				res = i - 1;
				break;
			}
			for (int j = 0; j < n; j++) {
				if (cur[j] == stus[j].a && ((slp << 1) <= n)) {
					cur[j] = 1;
				} else {
					cur[j] = cur[j] % (stus[j].a + stus[j].b) + 1;
				}
			}
			bool rep = true;
			for (int j = 0; j < n; j++) {
				if (cur[j] != stus[j].c) {
					rep = false;
					break;
				}
			}
			if (rep) {
				flag = false;
				break;
			}
		}
		cout << "Case " << ++k << ": ";
		if (flag) {
			cout << res << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
