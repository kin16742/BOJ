#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, res;
int arr[1005], dp[1005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
		dp[i] = max(dp[i], arr[i]);
	}
	cout << dp[n] << endl;
}