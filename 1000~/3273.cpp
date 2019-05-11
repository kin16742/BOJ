#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, x, a[100000];
ll cnt;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		int temp = x - a[i];
		if (binary_search(a + i + 1, a + n, temp)) {
			cnt += upper_bound(a + i + 1, a + n, temp) - lower_bound(a + i + 1, a + n, temp);
		}
	}
	cout << cnt << '\n';
	return 0;
}