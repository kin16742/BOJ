#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, Ya, Yb, val;
vector<pair<ll, ll>> dd;
vector<ll> res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> Ya >> Yb;

	for (int i = 0; i < n; i++) {
		cin >> val;
		dd.push_back({ val,Ya });
	}
	for (int i = 0; i < m; i++) {
		cin >> val;
		dd.push_back({ val,Yb });
	}

	sort(dd.begin(), dd.end());
	
	if (Ya != Yb) {
		for (int i = 1; i < dd.size(); i++) {
			if (dd[i - 1].second != dd[i].second) {
				val = abs(dd[i].second - dd[i - 1].second) + abs(dd[i].first - dd[i - 1].first);
				res.push_back(val);
			}
		}
	}
	else {
		for (int i = 1; i < dd.size(); i++) {
			val = abs(dd[i].second - dd[i - 1].second) + abs(dd[i].first - dd[i - 1].first);
			res.push_back(val);
		}
	}

	sort(res.begin(), res.end());
	cout << res[0] << ' ' << (int)(upper_bound(res.begin(), res.end(), res[0]) - lower_bound(res.begin(), res.end(), res[0])) << '\n';
	return 0;
}