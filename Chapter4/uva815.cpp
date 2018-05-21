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
vector<int> sqs, vol;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n, m;
	int k = 0;
	while (cin >> n >> m && n && m) {
		sqs.clear();
		vol.clear();
		sqs.resize(n*m);
		vol.resize(n*m);
		for (int i = 0; i < n*m; i++) {
			cin >> sqs[i];
		}
		sort(sqs.begin(), sqs.end());
		vol[0] = 0;
		for (int i = 1; i < n*m; i++) {
			vol[i] = vol[i - 1] + i * (sqs[i] - sqs[i - 1]);
		}
		int v;
		cin >> v;
		/*for (int i = 0; i < n*m; i++) {
			cout << vol[i] << ' ';
		}
		cout << endl;*/
		cout << "Region " << ++k << endl;
		if (!v) {
			cout << "Water level is "
				<< fixed << setprecision(2)
				<< (double)sqs.back()
				<< " meters." << endl;
			cout << "0.00 percent of the region is under water." << endl;
			cout << endl;
			continue;
		}
		else if (v > 100*vol.back()) {
			cout << "Water level is "
				<< fixed << setprecision(2)
				<< sqs.back() + (double)(v - 100*vol.back()) / (100*n*m)
				<< " meters." << endl;
			cout << "100.00 percent of the region is under water." << endl;
			cout << endl;
			continue;
		}
		int b = 1, e = n * m - 1;
		int btwn = -1;
		while (b <= e) {
			int mid = (b + e) / 2;
			if (100*vol[mid - 1] < v && v <= 100*vol[mid]) {
				btwn = mid;
				break;
			}
			else if (v <= 100*vol[mid-1]) {
				e = mid - 1;
			}
			else if (v > 100*vol[mid]) {
				b = mid + 1;
			}
		}
		cout << "Water level is "
			<< fixed << setprecision(2)
			<< sqs[btwn - 1] + (double)(sqs[btwn] - sqs[btwn - 1])*(v - 100*vol[btwn - 1]) / (100*vol[btwn] - 100*vol[btwn - 1])
			<< " meters." << endl;
		cout << fixed << setprecision(2) << (double)(btwn*100) / (n*m)
			<< " percent of the region is under water." << endl;
		cout << endl;
	}
	return 0;
}
