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
vector<int> num;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n, q;
	int k = 0;
	while (cin >> n >> q && n && q) {
		num.clear();
		num.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		sort(num.begin(), num.end());
		cout << "CASE# " << ++k << ':' << endl;
		for (int i = 0; i < q; i++) {
			int query;
			cin >> query;
			auto idx = lower_bound(num.begin(), num.end(), query);
			if (idx != num.end() && *idx == query) {
				cout << query << " found at " << (idx - num.begin())+1 << endl;
			} else {
				cout << query << " not found" << endl;
			}
		}
	}
	
	return 0;
}
