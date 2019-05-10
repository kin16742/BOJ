#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, k, temp, cnt, A[105], dp[10005];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp <= 10000) A[cnt] = temp;
		dp[A[cnt++]] = 1;
	}
	for (int i = 0; i <= k; i++) {
		if (dp[i] != 1) dp[i] = 100000;
	}
	for (int m = 0; m < n; m++) {
		for (int i = A[m]; i <= k; i++) {
			if (dp[i] - A[m] != 100000) dp[i] = min(dp[i], dp[i - A[m]] + 1);
		}
	}
	
	if (dp[k] == 100000) cout << -1 << '\n';
	else cout << dp[k] << '\n';
	return 0;
}