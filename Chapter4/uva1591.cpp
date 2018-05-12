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

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	long long n, p, q;
	while (cin >> n >> p >> q) {
		long long np = p * (n - 1);
		long long nq = q * n;
		long long best = (n * q) << 10;
		int besta = 0, bestb = 0;
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				long long cur = ((np + (np << i)) >> j) + q;
				if (cur >= nq && cur < best) {
					best = cur;
					besta = i;
					bestb = j;
				}
			}
		}
		cout << best << ' ' << besta << ' ' << bestb << endl;
	}
	
	return 0;
}
