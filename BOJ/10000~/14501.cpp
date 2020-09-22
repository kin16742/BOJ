#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, res;
int t[20], p[20];
int dp[20];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		if (i + t[i] > n + 1) {
			t[i] = 0;
			p[i] = 0;
		}
	}
	for (int i = n; i > 0; i--) {
		int next = i + t[i];
		if (next > n + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[next] + p[i]);
		}

	}

	cout << dp[1] << endl;
}