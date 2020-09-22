#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, k[250001], a, b, sTree[4000000], res;
char cm;

ll update(ll idx, ll val, ll node, ll left, ll right) {
	if (idx < left || idx > right) return sTree[node];
	if (left == right) return sTree[node] += val;
	ll mid = (left + right) / 2;
	return sTree[node] = update(idx, val, node * 2, left, mid) + update(idx, val, node * 2 + 1, mid + 1, right);
}

/*ll query(ll start, ll end, ll node, ll left, ll right) {
	if (left >= start && right <= end) return sTree[node];
	if (left > end || right < start) return 1;
	ll mid = (left + right) / 2;
	return query(start, end, node * 2, left, mid) * query(start, end, node * 2 + 1, mid + 1, right);
}*/

ll query(ll val, ll node, ll left, ll right) {
	if (left == right) return left;
	ll mid = (left + right) / 2;
	if (sTree[node * 2] >= val) return query(val, node * 2, left, mid);
	return query(val - sTree[node * 2], node * 2 + 1, mid + 1, right);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> k[i];

	for (int i = 0; i < m - 1; i++) {
		update(k[i], 1, 1, 0, 66666);
	}

	for (int i = m - 1; i < n; i++) {
		update(k[i], 1, 1, 0, 66666);
		res += query((m + 1) / 2, 1, 0, 66666);
		update(k[i - m + 1], -1, 1, 0, 66666);
	}
	cout << res << '\n';

	return 0;
}
