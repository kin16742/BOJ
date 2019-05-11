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
vector<pair<ll, ll>> v;

ll update(ll idx, ll val, ll node, ll left, ll right) {
	if (idx < left || idx > right) return sTree[node];
	if (left == right) return sTree[node] = val + 1;
	ll mid = (left + right) / 2;
	return sTree[node] = max(update(idx, val, node * 2, left, mid), update(idx, val, node * 2 + 1, mid + 1, right));
}

ll query(ll start, ll end, ll node, ll left, ll right) {
	if (left >= start && right <= end) return sTree[node];
	if (left > end || right < start) return 0;
	ll mid = (left + right) / 2;
	return max(query(start, end, node * 2, left, mid), query(start, end, node * 2 + 1, mid + 1, right));
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> k;
			v.push_back({ k,-i });
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			update(-v[i].second, query(1, -v[i].second, 1, 1, n), 1, 1, n);
		}

		cout << sTree[1] << '\n';
		
		v.clear();
		memset(sTree, 0, sizeof(sTree));
	}
	return 0;
}