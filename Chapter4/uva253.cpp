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
using namespace std;

const int trans[][7] = {
	{0},
{0,0,3,5,2,4,0},
{0,4,0,1,6,0,3},
{0,2,6,0,0,1,5},
{0,5,1,0,0,6,2},
{0,3,0,6,1,0,4},
{0,0,4,2,5,3,0}
};

bool solve(string a, string b) {
	for (int i = 1; i <= 6; i++) {
		if (b[i] == a[1] && b[7 - i] == a[6]) {
			for (int j = 1; j <= 6; j++) {
				if (j == i || j == 7 - i) {
					continue;
				}
				if (b[j] == a[2] && b[7 - j] == a[5]) {
					if (b[trans[i][j]] == a[3] && b[7 - trans[i][j]] == a[4]) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	string str;
	while (cin >> str) {
		string a = str.substr(0, 6), b = str.substr(6);
		a.insert(0, 1, '$');
		b.insert(0, 1, '$');
		bool flag = solve(a, b);
		if (flag) {
			cout << "TRUE" << endl;
		} else {
			cout << "FALSE" << endl;
		}
	}
	return 0;
}
