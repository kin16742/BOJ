#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a[10000], res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			if (a[i + 1] <= 0 && i + 1 < n) {
				res += a[i] * a[i + 1];
				i++;
			}
			else {
				res += a[i];
			}
		}
		else if (a[i] == 1) res++;
		else if (a[i] > 1) {
			if ((n - i) % 2 == 0) {
				res += a[i] * a[i + 1];
				i++;
			}
			else {
				res += a[i];
			}
		}
	}
	cout << res << '\n';
	return 0;
}