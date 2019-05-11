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
vector<pair<int, int>> v;

ll update(ll idx, ll val, ll node, ll left, ll right) {
	if (idx < left || idx > right) return sTree[node];
	if (left == right) return sTree[node] += val;
	ll mid = (left + right) / 2;
	return sTree[node] = update(idx, val, node * 2, left, mid) + update(idx, val, node * 2 + 1, mid + 1, right);
}

ll query(ll start, ll end, ll node, ll left, ll right) {
	if (left >= start && right <= end) return sTree[node];
	if (left > end || right < start) return 0;
	ll mid = (left + right) / 2;
	return query(start, end, node * 2, left, mid) + query(start, end, node * 2 + 1, mid + 1, right);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> k;

		if (k == 1) {
			int cnt = 0;
			cin >> a;
			while (a > 0) {
				a -= v[cnt++].second;
			}
			cnt--;
			cout << v[cnt].first << '\n';
			v[cnt].second--;
			if (v[cnt].second == 0) {
				v.erase(v.begin() + cnt);
			}
			update(v[cnt].first, -1, 1, 1, 1000000);
		}
		if (k == 2) {
			bool t = false;

			cin >> a >> b;

			for (int i = 0; i < v.size(); i++) {
				if (v[i].first == a) {
					v[i].second += b;
					if (v[i].second == 0) {
						v.erase(v.begin() + i);
					}
					t = true;
					break;
				}
			}
			if (!t) v.push_back({ a,b });
			sort(v.begin(), v.end());

			update(a, b, 1, 1, 1000000);
		}
	}

	return 0;
}
