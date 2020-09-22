#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int A[100001], dp[100001], n, res = -1000000000;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] + A[i] > A[i]) dp[i] = dp[i - 1] + A[i];
		else dp[i] = A[i];
	}
	for (int i = 1; i <= n; i++) res = max(res, dp[i]);
	cout << res << '\n';
	return 0;
}