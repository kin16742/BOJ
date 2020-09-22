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
		if (temp <= 10000) A[cnt++] = temp;
	}
	dp[0] = 1;
	for (int m = 0; m < cnt; m++) {
		for (int i = A[m]; i <= k; i++) {
			if (dp[i - A[m]] != 0) dp[i] += dp[i - A[m]];
		}
	}
	
	cout << dp[k] << '\n';
	return 0;
}