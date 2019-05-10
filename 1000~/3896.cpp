#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int p[1300000], t;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	p[1] = 1;
	int range = sqrt(1300000);
	for (int i = 2; i < range; i++) {
		if (p[i] == 1) continue;
		for (int j = i + i; j <= 1300000; j += i) {
			p[j] = 1;
		}
	}
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		if (p[k] == 0) cout << 0 << '\n';
		else {
			int res = 2;
			int temp1 = k - 1, temp2 = k + 1;
			while (p[temp1] != 0) {
				temp1--;
				res++;
			}
			while (p[temp2] != 0) {
				temp2++;
				res++;
			}
			cout << res << '\n';
		}
	}
	return 0;
}