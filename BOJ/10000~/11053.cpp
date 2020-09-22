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
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j])
				temp = max(temp, dp[j]);
		}
		dp[i] = temp + 1;
	}
	for (int i = 1; i <= n; i++)
		res = max(res, dp[i]);
	cout << res << endl;
}