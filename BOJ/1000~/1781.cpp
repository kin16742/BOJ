#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a, b, mx;
ll res;
vector<pair<int, int>> v;
priority_queue<int> pq;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	for (int i = n, j = n - 1; i > 0; i--) {
		while (j >= 0 && v[j].first == i) {
			pq.push(v[j--].second);
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res << '\n';
	return 0;
}