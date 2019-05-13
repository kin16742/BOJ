#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, a[1000000], b, c, cnt = 0;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		cnt++;
		if (a[i] > 0) {
			cnt += a[i] / c;
			if (a[i] % c != 0) cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;

}