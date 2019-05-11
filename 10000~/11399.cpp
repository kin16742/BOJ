#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a[1000];
ll res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}

	for (int i = 0; i < n; i++) {
		res += a[i];
	}
	cout << res << '\n';

	return 0;
}