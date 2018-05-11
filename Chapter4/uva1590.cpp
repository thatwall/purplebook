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
	int m;
	while (cin >> m) {
		unsigned res = 0;
		int maxidx = -1;
		for (int i = 0; i < m; i++) {
			unsigned a, b, c, d;
			scanf("%u.%u.%u.%u", &a, &b, &c, &d);
			unsigned sum = (a << 24) | (b << 16) | (c << 8) | d;
			if (!i) {
				res = sum;
				continue;
			}
			unsigned diff = res ^ sum;
			int idx = 31;
			for (; idx >= 0; idx--) {
				if (diff & (1 << idx)) {
					break;
				}
			}
			if (maxidx < idx) {
				maxidx = idx;
				res = (res >> (maxidx + 1)) << (maxidx + 1);
			}
		}
		printf("%u.%u.%u.%u\n", res >> 24, (res << 8) >> 24, (res << 16) >> 24, (res << 24) >> 24);
		unsigned mm = 0xffffffff;
		mm <<= maxidx + 1;
		if (maxidx == 31) {
			mm = 0;
		}
		printf("%u.%u.%u.%u\n", mm >> 24, (mm << 8) >> 24, (mm << 16) >> 24, (mm << 24) >> 24);
	}
	return 0;
}
