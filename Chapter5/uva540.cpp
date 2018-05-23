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

map<int, int> x2t;
map<int, queue<int>> t2q;
queue<int> qoft;

void enqueue(int x) {
	int t = x2t[x];
	if (!t2q.count(t)) {
		qoft.push(t);
	}
	t2q[t].push(x);
}

void dequeue() {
	if (qoft.empty()) {
		return;
	}
	int top = qoft.front();
	int val = t2q[top].front();
	cout << val << endl;
	if (t2q[top].size() == 1) {
		qoft.pop();
		t2q.erase(top);
	} else {
		t2q[top].pop();
	}
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int t;
	int k = 0;
	while (cin >> t && t) {
		cout << "Scenario #" << ++k << endl;
		x2t.clear();
		t2q.clear();
		qoft = queue<int>();
		for (int i = 0; i < t; i++) {
			int tn;
			cin >> tn;
			while (tn--) {
				int x;
				cin >> x;
				x2t[x] = i;
			}
		}
		string op;
		while (cin >> op && op[0] != 'S') {
			if (op[0] == 'E') {
				int x;
				cin >> x;
				enqueue(x);
			} else {
				dequeue();
			}
		}
		cout << endl;
	}
	return 0;
}
