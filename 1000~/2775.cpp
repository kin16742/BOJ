#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int t, k, n, apt[15][15];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 15; i++) {
		apt[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			apt[i][j] = apt[i - 1][j] + apt[i][j - 1];
		}
	}
	cin >> t;
	while (t--) {
		cin >> k >> n;
		cout << apt[k][n] << '\n';
	}
	return 0;
}
