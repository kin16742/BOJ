#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int m, p[4000001], cnt, s[4000001], res, sum, lo, hi;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	int range = sqrt(4000000);
	for (int i = 2; i <= range; i++) {
		if (p[i] == 1) continue;
		for (int j = i + i; j <= 4000000; j += i) {
			p[j] = 1;
		}
	}
	for (int i = 2; i <= 4000000; i++) {
		if (p[i] == 0) s[cnt++] = i;
	}
	while (1) {
		if (sum >= m) sum -= s[lo++];
		else if (hi == cnt) break;
		else sum += s[hi++];
		if (sum == m) res++;
	}
	cout << res << '\n';
	return 0;
}