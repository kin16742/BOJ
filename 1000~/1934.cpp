#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, t, k;
int arr[1005], dp[1005];
int main() {
	cin >> k;
	while (k--) {
		cin >> n >> m;
		t = n * m;
		while (max(n, m) % min(m, n) != 0) {
			if (m > n) m = m % n;
			else if (m < n) n = n % m;
		}
		t /= min(m, n);
		cout << t << endl;
	}
}