#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, s, a[21], cnt;

void chk(int i, int sum) {
	if (i >= n) {
		if (sum == s) cnt++;
		return;
	}

	chk(i + 1, sum);
	chk(i + 1, sum + a[i]);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	chk(1, 0);
	chk(1, a[0]);

	if (s == 0) cnt--;
	
	cout << cnt << '\n';
	
	return 0;
}