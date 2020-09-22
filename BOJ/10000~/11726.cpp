#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
int n, x;
int dp[1005];

int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n] << endl;
}