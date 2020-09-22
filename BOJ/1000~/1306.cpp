#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, k, sTree[4000000];

ll update(ll idx, ll val, ll node, ll left, ll right) {
	if (idx < left || idx > right) return sTree[node];
	if (right == left) return sTree[node] = val;
	ll mid = (left + right) / 2;
	return sTree[node] = max(update(idx, val, node * 2, left, mid), update(idx, val, node * 2 + 1, mid + 1, right));
}

ll query(ll start, ll end, ll node, ll left, ll right) {
	if (left > end || right < start) return -1;
	if (left >= start && right <= end) return sTree[node];
	ll mid = (left + right) / 2;
	return max(query(start, end, node * 2, left, mid), query(start, end, node * 2 + 1, mid + 1, right));
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		update(i, k, 1, 1, n);
	}
	for (int i = m; i <= n - m + 1; i++) {
		cout << query(i - m + 1, i + m - 1, 1, 1, n) << ' ';
	}
	cout << '\n';
	return 0;
}