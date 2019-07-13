#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, sum, res;
int p[10005];
int main() {
	cin >> n >> m;
	p[0] = 1;
	p[1] = 1;
	for (int i = 2; i <= sqrt(10000); i++) {
		if (!p[2]) {
			for (int j = i + i; j <= 10000; j += i)
				p[j] = 1;
		}
	}
	for (int i = n; i <= m; i++) {
		if (!p[i]) {
			sum += i;
			if (res == 0) res = i;
		}
	}
	if (sum == 0) cout << -1 << endl;
	else cout << sum << endl << res << endl;
}