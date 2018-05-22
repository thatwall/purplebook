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
using namespace std;
vector<set<int>> m;
stack<int> s;
map<set<int>, int> tbl;
void print() {
	cout << m[s.top()].size() << endl;
}

void func(char op) {
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();
	auto ma = m[a], mb = m[b];
	set<int> mc;
	if (op == 'U') {
		set_union(ma.begin(), ma.end(), mb.begin(), mb.end(), inserter(mc,mc.begin()));
	}
	else if (op == 'I') {
		set_intersection(ma.begin(), ma.end(), mb.begin(), mb.end(), inserter(mc, mc.begin()));
	} else {
		mc = mb;
		mc.insert(a);
	}
	if (tbl.count(mc)) {
		int mcidx = tbl[mc];
		s.push(mcidx);
	} else {
		tbl[mc] = m.size();
		s.push(m.size());
		m.push_back(mc);
	}
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int t;
	cin >> t;
	while (t--) {
		m.clear();
		tbl.clear();
		s = stack<int>();

		m.push_back(set<int>());
		tbl[set<int>()] = 0;

		int n;
		cin >> n;
		while (n--) {
			string op;
			cin >> op;
			switch (op[0]) {
			case 'P': s.push(0); print(); break;
			case 'D': s.push(s.top()); print(); break;
			default:
				func(op[0]);
				print();
				break;
			}
		}
		cout << "***" << endl;
	}
	return 0;
}
