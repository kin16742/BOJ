#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, s, a[40], cnt;

vector<int> v, v2;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n > 20) {
		for (int i = 0; i < (1 << 20); i++) {
			int sum = 0;
			for (int j = 0; j < 20; j++) {
				if (i&(1 << j)) sum += a[j];
			}
			v.push_back(sum);
		}
		sort(v.begin(), v.end());

		ll *p = &a[20];
		for (int i = 0; i < (1 << n - 20); i++) {
			int sum = 0;
			for (int j = 0; j < n - 20; j++) {
				if (i&(1 << j)) sum += p[j];
			}
			v2.push_back(sum);
		}
		sort(v2.begin(), v2.end());
		for (int i = 0; i < v2.size(); i++) {
			int temp = s - v2[i];
			cnt += (int)(upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp));
		}
		if (s == 0) cnt--;
	}
	else {
		for (int i = 0; i < (1 << n); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (i&(1 << j)) sum += a[j];
			}
			v.push_back(sum);
		}
		sort(v.begin(), v.end());

		cnt = (int)(upper_bound(v.begin(), v.end(), s) - lower_bound(v.begin(), v.end(), s));
		if (s == 0) cnt--;
	}
	cout << cnt << '\n';
	return 0;
}