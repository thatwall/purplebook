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
const string igno[] = { "the","a", "to","and","or","not" };
const set<string> ignoset(igno, igno + 6);
vector<vector<string>> docs;
map<string, map<int, set<int> > > inv;

void readline(int doc, int line) {
	auto str = docs[doc][line];
	string word;
	for (int i = 0; i < str.size(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			word += str[i];
		}
		else if ('A' <= str[i] && str[i] <= 'Z') {
			word += (str[i] - 'A' + 'a');
		} else {
			if (!word.empty() && !ignoset.count(word)) {
				inv[word][doc].insert(line);
			}
			word.clear();
		}
	}
	if (!word.empty() && !ignoset.count(word)) {
		inv[word][doc].insert(line);
	}
}

void solveAnd(string str, int idx) {
	string str1 = str.substr(0, idx - 1), str2 = str.substr(idx + 4);
	if (!inv.count(str1) || !inv.count(str2)) {
		cout << "Sorry, I found nothing." << endl;
		cout << "==========" << endl;
		return;
	}
	auto &pos1 = inv[str1], &pos2 = inv[str2];
	bool first = true, flag = false;
	for (int i = 0; i < docs.size(); i++) {
		if (pos1.count(i) && pos2.count(i)) {
			set<int> un;
			set_union(pos1[i].begin(), pos1[i].end(), pos2[i].begin(), pos2[i].end(), inserter(un, un.begin()));
			flag = true;
			if (first) {
				first = false;
			} else {
				cout << "----------" << endl;
			}
			for (auto j : un) {
				cout << docs[i][j] << endl;
			}
		}
	}
	if (!flag) {
		cout << "Sorry, I found nothing." << endl;
	}
	cout << "==========" << endl;
}

void solveOr(string str, int idx) {
	string str1 = str.substr(0, idx - 1), str2 = str.substr(idx + 3);
	if (!inv.count(str1) && !inv.count(str2)) {
		cout << "Sorry, I found nothing." << endl;
		cout << "==========" << endl;
		return;
	}
	else if (!inv.count(str1)) {
		bool first = true;
		for (auto i : inv[str2]) {
			if (first) {
				first = false;
			} else {
				cout << "----------" << endl;
			}
			for (auto j : i.second) {
				cout << docs[i.first][j] << endl;
			}
		}
		cout << "==========" << endl;
		return;
	}
	else if (!inv.count(str2)) {
		bool first = true;
		for (auto i : inv[str1]) {
			if (first) {
				first = false;
			} else {
				cout << "----------" << endl;
			}
			for (auto j : i.second) {
				cout << docs[i.first][j] << endl;
			}
		}
		cout << "==========" << endl;
		return;
	}
	auto &pos1 = inv[str1], &pos2 = inv[str2];
	bool first = true;
	for (int i = 0; i < docs.size(); i++) {
		if (pos1.count(i) && pos2.count(i)) {
			set<int> un;
			set_union(pos1[i].begin(), pos1[i].end(), pos2[i].begin(), pos2[i].end(), inserter(un, un.begin()));
			if (first) {
				first = false;
			} else {
				cout << "----------" << endl;
			}
			for (auto j : un) {
				cout << docs[i][j] << endl;
			}
		}
		else if (pos1.count(i)) {
			if (first) {
				first = false;
			} else {
				cout << "----------" << endl;
			}
			for (auto j : pos1[i]) {
				cout << docs[i][j] << endl;
			}
		}
		else if (pos2.count(i)) {
			if (first) {
				first = false;
			} else {
				cout << "----------" << endl;
			}
			for (auto j : pos2[i]) {
				cout << docs[i][j] << endl;
			}
		}
	}
	cout << "==========" << endl;
}

void solveNot(string str) {
	bool first = true;
	if (!inv.count(str)) {
		for (int i = 0; i < docs.size(); i++) {
			if (first) {
				first = false;
			} else {
				cout << "----------" << endl;
			}
			for (int j = 0; j < docs[i].size(); j++) {
				cout << docs[i][j] << endl;
			}
		}
		cout << "==========" << endl;
		return;
	}
	bool flag = true;
	for (int i = 0; i < docs.size(); i++) {
		if (!inv[str].count(i)) {
			flag = false;
			if (first) {
				first = false;
			} else {
				cout << "----------" << endl;
			}
			for (auto j : docs[i]) {
				cout << j << endl;
			}
		}
	}
	if (flag) {
		cout << "Sorry, I found nothing." << endl;
	}
	cout << "==========" << endl;
}

void solve(string str) {
	if (!inv.count(str)) {
		cout << "Sorry, I found nothing." << endl;
		cout << "==========" << endl;
		return;
	}
	bool first = true;
	for (auto i : inv[str]) {
		if (first) {
			first = false;
		} else {
			cout << "----------" << endl;
		}
		for (auto j : i.second) {
			cout << docs[i.first][j] << endl;
		}
	}
	cout << "==========" << endl;
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n;
	cin >> n;
	docs.resize(n);
	getchar();
	for (int i = 0; i < n; i++) {
		string line;
		while (getline(cin, line) && line != "**********") {
			docs[i].push_back(line);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < docs[i].size(); j++) {
			readline(i, j);
		}
	}
	int m;
	cin >> m;
	getchar();
	while (m--) {
		string query;
		getline(cin, query);
		int idx;
		if ((idx = query.find('A')) != query.npos) {
			solveAnd(query, idx);
		}
		else if ((idx = query.find('N')) != query.npos) {
			solveNot(query.substr(4));
		}
		else if ((idx = query.find('O')) != query.npos) {
			solveOr(query, idx);
		} else {
			solve(query);
		}
	}
	return 0;
}
