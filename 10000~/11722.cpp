#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1050], dp[1050], result;
int main() {
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i<n; i++) {
		dp[i] = 1;
		for (int j = 0; j<i; j++) {
			if (a[i] < a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = 0; i<n; i++) {
		result = max(result, dp[i]);
	}
	cout << result << endl;
}