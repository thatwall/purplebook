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

map<string, string> om, nm;
set<string> plu;
set<string> modif;

void trans(map<string, string> &m, string str) {
	string key, val;
	bool sta = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ':') {
			sta = false;
		}
		else if (str[i] == ',') {
			sta = true;
			if (!key.empty() && !val.empty()) {
				m[key] = val;
			}
			key.clear();
			val.clear();
		}
		else if (sta) {
			key += str[i];
		} else {
			val += str[i];
		}
	}
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int t;
	cin >> t;
	while (t--) {
		om.clear();
		nm.clear();
		plu.clear();
		modif.clear();
		string old, nd;
		cin >> old >> nd;
		old.back() = ',';
		nd.back() = ',';
		trans(om, old.substr(1));
		trans(nm, nd.substr(1));
		for (auto it : nm) {
			auto &k = it.first;
			auto &v = it.second;
			if (!om.count(k)) {
				plu.insert(k);
			} else {
				if (om[k] != v) {
					modif.insert(k);
				}
				om.erase(k);
			}
		}
		bool flag = true;
		if (!plu.empty()) {
			flag = false;
			cout << '+';
			bool first = true;
			for (auto i : plu) {
				if (first) {
					first = false;
				} else {
					cout << ',';
				}
				cout << i;
			}
			cout << endl;
		}
		if (!om.empty()) {
			flag = false;
			bool first = true;
			cout << '-';
			for (auto i : om) {
				if (first) {
					first = false;
				} else {
					cout << ',';
				}
				cout << i.first;
			}
			cout << endl;
		}
		if (!modif.empty()) {
			flag = false;
			cout << '*';
			bool first = true;
			for (auto i : modif) {
				if (first) {
					first = false;
				} else {
					cout << ',';
				}
				cout << i;
			}
			cout << endl;
		}
		if (flag) {
			cout << "No changes" << endl;
		}
		cout << endl;
	}
	return 0;
}
