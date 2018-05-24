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
priority_queue<long long, vector<long long>, greater<long long> > q;
set<long long> s;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	q.push(1);
	s.insert(1);
	for (int i = 1; i <= 1500; i++) {
		long long top = q.top();
		if (i == 1500) {
			cout << "The 1500'th ugly number is " << top << '.' << endl;
			break;
		}
		q.pop();
		s.erase(top);
		if (s.find(2 * top) == s.end()) {
			s.insert(2 * top);
			q.push(2 * top);
		}
		if (s.find(3 * top) == s.end()) {
			s.insert(3 * top);
			q.push(3 * top);
		}
		if (s.find(5 * top) == s.end()) {
			s.insert(5 * top);
			q.push(5 * top);
		}
	}
	return 0;
}
