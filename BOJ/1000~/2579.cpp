#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<string.h>
using namespace std;

int main()
{
	int n;
	int arr[300];
	int dp[301] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) dp[0] = arr[0];
		else if (i == 1) dp[i] = arr[0] + arr[1];
		else if (i == 2) dp[i] = max(arr[0], arr[1]) + arr[2];
		else {
			dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		}
	}
	cout << dp[n - 1] << '\n';
}