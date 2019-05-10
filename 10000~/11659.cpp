#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, A[100001], a, b;
long long res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	while (m--) {
		cin >> a >> b;
		cout << A[max(a, b)] - A[min(a - 1, b - 1)] << '\n';
	}
	return 0;
}