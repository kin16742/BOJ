#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, k, a, b, mx;
ll res;
vector<pair<int, int>> v;
vector<int> c;
priority_queue<int> pq;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < k; i++) {
		cin >> a;
		c.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(c.begin(), c.end());
	
	for (int i = 0, j = 0; i < k; i++) {
		while (j < n && v[j].first <= c[i]) {
			pq.push(v[j++].second);
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res << '\n';
	return 0;
}