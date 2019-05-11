#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a[500001], res[500001], num;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (binary_search(a, a + n, num)) {
			res[i] = 1;
		}
		else res[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
	return 0;
}