#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a[15001];
ll cnt;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		int temp = m - a[i];
		if (binary_search(a + i + 1, a + n, temp)) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}