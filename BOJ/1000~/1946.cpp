#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int t, n;
pair<int, int> dd[100000];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(dd, 0, sizeof(dd));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> dd[i].first >> dd[i].second;
		}
		sort(dd, dd + n);
		int cnt = 0;
		int lim = 1000000000;
		for (int i = 0; i < n; i++) {
			if (dd[i].second < lim) {
				cnt++;
				lim = dd[i].second;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}