#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, a[10], res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	do {
		if (n % 10 == 6) a[9]++;
		else a[n % 10]++;
		n /= 10;
	} while (n != 0);
	a[9] = (a[9] + 1) / 2;
	for (int i = 0; i < 10; i++) res = max(res, a[i]);
	cout << res << '\n';
	return 0;
}