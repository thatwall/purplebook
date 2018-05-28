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

struct buliding {
	int id;
	double x, y, w, d, h;
	bool operator<(const buliding& b) const {
		if (x == b.x) {
			return y < b.y;
		}
		return x < b.x;
	}
};
vector<buliding> bs;
vector<double> xitv;
set<buliding> bset;
istream& operator>>(istream& in, buliding& b) {
	in >> b.x >> b.y >> b.w >> b.d >> b.h;
	xitv.push_back(b.x);
	xitv.push_back(b.x + b.w);
	return in;
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int bnum;
	int k = 0;
	while (cin >> bnum && bnum) {
		bs.clear();
		bs.resize(bnum);
		xitv.clear();
		bset.clear();
		for (int i = 0; i < bnum; i++) {
			cin >> bs[i];
			bs[i].id = i + 1;
		}

		sort(xitv.begin(), xitv.end());
		auto it = unique(xitv.begin(), xitv.end());
		xitv.resize(distance(xitv.begin(), it));
		sort(bs.begin(), bs.end());

		for (int i = 0; i < xitv.size()-1; i++) {
			auto l = xitv[i], r = xitv[i + 1];
			vector<buliding> t;
			for (int j = 0; j < bnum; j++) {
				auto b = bs[j];
				if (b.x <= l && r <= b.x+b.w) {
					t.push_back(b);
				}
			}
			if (t.empty()) {
				continue;
			}
			sort(t.begin(), t.end(), [&](buliding &a, buliding &b) {
				return a.y < b.y;
			});
			bset.insert(t[0]);
			int maxh = t[0].h;
			for (int j = 1; j < t.size(); j++) {
				if (maxh < t[j].h) {
					bset.insert(t[j]);
					maxh = t[j].h;
				}
			}
		}
		if (k) {
			cout << endl;
		}
		cout << "For map #" << ++k;
		cout << ", the visible buildings are numbered as follows:" << endl;
		for (auto i = bset.begin(); i != bset.end(); i++) {
			if (i != bset.begin()) {
				cout << ' ';
			}
			cout << i->id;
		}
		cout << endl;
	}
	return 0;
}
