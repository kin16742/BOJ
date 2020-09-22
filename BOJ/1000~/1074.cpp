#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, r, c, res;

void zet(int a, int b, int s) {
	if (s == 0) return;
	int x = a + pow(2, s) / 2;
	int y = b + pow(2, s) / 2;
	
	if (c < x && r < y) {
		zet(a, b, s - 1);
	}
	else if (c >= x && r < y) {
		res += pow(2, s - 1) * pow(2, s - 1);
		zet(x, b, s - 1);
	}
	else if (c < x && r >= y) {
		res += 2 * pow(2, s - 1) * pow(2, s - 1);
		zet(a, y, s - 1);
	}
	else {
		res += 3 * pow(2, s - 1) * pow(2, s - 1);
		zet(x, y, s - 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> c;
	zet(0, 0, n);
	cout << res << '\n';
	return 0;
}