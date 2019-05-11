#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int t;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int n, k, a, res = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a;
			res += a / k;
		}
		cout << res << '\n';
	}
	return 0;
}