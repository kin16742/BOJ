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
char cm;

ll update(ll idx, ll val, ll node, ll left, ll right) {
	if (idx < left || idx > right) return sTree[node];
	if (left == right) return sTree[node] = val;
	ll mid = (left + right) / 2;
	return sTree[node] = update(idx, val, node * 2, left, mid) * update(idx, val, node * 2 + 1, mid + 1, right);
}

ll query(ll start, ll end, ll node, ll left, ll right) {
	if (left >= start && right <= end) return sTree[node];
	if (left > end || right < start) return 1;
	ll mid = (left + right) / 2;
	return query(start, end, node * 2, left, mid) * query(start, end, node * 2 + 1, mid + 1, right);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> m) {
		memset(sTree, 0, sizeof(sTree));

		for (int i = 1; i <= n; i++) {
			cin >> k;
			if (k == 0) update(i, 0, 1, 1, n);
			if (k > 0) update(i, 1, 1, 1, n);
			if (k < 0) update(i, -1, 1, 1, n);
		}

		for (int i = 0; i < m; i++) {
			cin >> cm;
			if (cm == 'C') {
				cin >> a >> b;
				if (b == 0) update(a, 0, 1, 1, n);
				if (b > 0) update(a, 1, 1, 1, n);
				if (b < 0) update(a, -1, 1, 1, n);
			}
			if (cm == 'P') {
				cin >> a >> b;
				ll res = query(a, b, 1, 1, n);
				if (res == 0) cout << 0;
				if (res > 0) cout << '+';
				if (res < 0) cout << '-';
			}
		}

		cout << '\n';
	}

	return 0;
}
