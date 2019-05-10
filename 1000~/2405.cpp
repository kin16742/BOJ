#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, max1 = -100000000, result1;
	int A[100000];
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, A + n);
	
	for (int i = 0; i < n - 2; i++) {
		result1 = abs(A[i] + A[n - 1] - 2 * A[i + 1]);
		if (result1 > max1) max1 = result1;
	}
	
	for (int i = 1; i < n - 1; i++) {
		result1 = abs(2 * A[i] - A[0] - A[i + 1]);
		if (result1 > max1) max1 = result1;
	}
	
	
	cout << max1 << '\n';
	
	return 0;
}