#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, k, a, b, sTreeA[4000000], sTreeB[4000000];

ll updateA(ll idx, ll val, ll node, ll left, ll right) {
	if (idx < left || idx > right) return sTreeA[node];
	if (left == right) return sTreeA[node] = val;
	ll mid = (left + right) / 2;
	return sTreeA[node] = max(updateA(idx, val, node * 2, left, mid), updateA(idx, val, node * 2 + 1, mid + 1, right));
}

ll queryA(ll start, ll end, ll node, ll left, ll right) {
	if (left >= start && right <= end) return sTreeA[node];
	if (left > end || right < start) return -1;
	ll mid = (left + right) / 2;
	return max(queryA(start, end, node * 2, left, mid), queryA(start, end, node * 2 + 1, mid + 1, right));
}

ll updateB(ll idx, ll val, ll node, ll left, ll right) {
	if (idx < left || idx > right) return sTreeB[node];
	if (left == right) return sTreeB[node] = val;
	ll mid = (left + right) / 2;
	return sTreeB[node] = min(updateB(idx, val, node * 2, left, mid), updateB(idx, val, node * 2 + 1, mid + 1, right));
}

ll queryB(ll start, ll end, ll node, ll left, ll right) {
	if (left >= start && right <= end) return sTreeB[node];
	if (left > end || right < start) return 2000000000000;
	ll mid = (left + right) / 2;
	return min(queryB(start, end, node * 2, left, mid), queryB(start, end, node * 2 + 1, mid + 1, right));
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a;
		updateA(i, a, 1, 1, n);
		updateB(i, a, 1, 1, n);
	}
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b;
		cout << queryB(a, b, 1, 1, n) << ' ' << queryA(a, b, 1, 1, n) << '\n';
	}
	return 0;
}