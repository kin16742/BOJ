#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, k, a, b, sTree[4000000];

ll update(ll idx, ll val, ll node, ll left, ll right) {
	if (idx < left || idx > right) return sTree[node];
	if (left == right) return sTree[node] += val;
	ll mid = (left + right) / 2;
	return sTree[node] = update(idx, val, node * 2, left, mid) + update(idx, val, node * 2 + 1, mid + 1, right);
}

ll query(ll val, ll node, ll left, ll right) {
	if (left == right) return left;
	ll mid = (left + right) / 2;
	if (val <= sTree[node * 2]) return query(val, node * 2, left, mid);
	else return query(val - sTree[node * 2], node * 2 + 1, mid + 1, right);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> k;
		update(i, k, 1, 1, n);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> k;

		if (k == 1) {
			cin >> a >> b;
			update(a, b, 1, 1, n);
		}
		if (k == 2) {
			cin >> a;
			cout << query(a, 1, 1, n) << '\n';
		}
	}

	return 0;
}