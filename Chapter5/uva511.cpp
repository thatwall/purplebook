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

struct mmap {
	string name;
	double x1, y1, x2, y2;
	mmap(string n = "", double a = 0, double b = 0, double c = 0, double d = 0) {
		name = n;
		x1 = a, y1 = b, x2 = c, y2 = d;
	}
	bool isin(double x, double y) {
		auto mx = min(x1, x2), Mx = max(x1, x2);
		auto my = min(y1, y2), My = max(y1, y2);
		return mx <= x && x <= Mx && my <= y && y <= My;
	}
	double area() {
		return fabs(x1 - x2)*fabs(y1 - y2);
	}
	double centralDis(double x, double y) {
		auto cx = (x1 + x2) / 2, cy = (y1 + y2) / 2;
		return (x - cx)*(x - cx) + (y - cy)*(y - cy);
	}
	double ratio() {
		return fabs(y1 - y2) / fabs(x1 - x2);
	}
	double lowerRightDis(double x, double y) {
		auto tx = max(x1, x2), ty = min(y1, y2);
		return (x - tx)*(x - tx) + (y - ty)*(y - ty);
	}
	double minx() {
		return min(x1, x2);
	}
};
vector<mmap> mmaps;

bool mmapcmp(mmap &a, mmap &b, double curX, double curY) {
	if (a.centralDis(curX, curY) != b.centralDis(curX, curY)) {
		return a.centralDis(curX, curY) > b.centralDis(curX, curY);
	} else if (a.ratio() != b.ratio()) {
		return fabs(0.75 - a.ratio()) > fabs(0.75 - b.ratio());
	} else if (a.lowerRightDis(curX, curY) != b.lowerRightDis(curX, curY)) {
		return a.lowerRightDis(curX, curY) < b.lowerRightDis(curX, curY);
	}
	return a.minx() > b.minx();
}

struct loc {
	double x, y;
	loc(double a = 0, double b = 0) {
		x = a, y = b;
	}
	void getm() {
		for (auto &i : mmaps) {
			if (i.isin(x,y)) {
				if (assom.count(i.area())) {
					if (mmapcmp(assom[i.area()], i, x, y)) {
						assom[i.area()] = i;
					}
				} else {
					assom[i.area()] = i;
				}
			}
		}
	}
	void getres() {
		for (auto i : assom) {
			res.push_back(i.second.name);
		}
	}
	map<double, mmap> assom;
	vector<string> res;
};

map<string, loc> locs;

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	string str;
	cin >> str;
	while (cin >> str && str != "LOCATIONS") {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		mmaps.push_back(mmap(str, x1, y1, x2, y2));
	}
	while (cin >> str && str != "REQUESTS") {
		double x, y;
		cin >> x >> y;
		locs[str] = loc(x, y);
	}
	for (auto &i : locs) {
		i.second.getm();
		i.second.getres();
	}
	while (cin >> str && str != "END") {
		int level;
		cin >> level;
		cout << str << " at detail level " << level;
		if (!locs.count(str)) {
			cout << " unknown location" << endl;
			continue;
		}
		auto &l = locs[str];
		if (l.assom.empty()) {
			cout << " no map contains that location" << endl;
		}
		else if (l.assom.size() < level) {
			cout << " no map at that detail level; using " << l.res.front() << endl;
		} else {
			cout << " using " << l.res[l.res.size() - level] << endl;
		}
	}
	return 0;
}
