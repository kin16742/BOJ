#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int p[10001], m, n, first = 100000, sum;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int range = sqrt(10000);
	for (int i = 1; i <= range; i++) p[i * i] = 1;

	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (p[i] == 1) {
			sum += i;
			first = min(first, i);
		}
	}
	if (!sum) cout << -1 << '\n';
	else cout << sum << '\n' << first << '\n';
	return 0;
}