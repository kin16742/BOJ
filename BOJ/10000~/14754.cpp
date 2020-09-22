#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, dd[1001][1001], sum;
vector<ll> v;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dd[i][j];
			sum += dd[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		ll val = 0;
		for (int j = 0; j < m; j++) {
			val = max(val, dd[i][j]);
		}
		v.push_back(val);
	}
	for (int i = 0; i < m; i++) {
		ll val = 0;
		for (int j = 0; j < n; j++) {
			val = max(val, dd[j][i]);
		}
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		sum -= v[i];
	}
	cout << sum << '\n';
	return 0;
}