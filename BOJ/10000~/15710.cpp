#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int a, b, n;
long long calc(long long v, long long p) {
	if (p == 0) return 1;
	if (p % 2 == 0) return calc(v * v % 1000000007, p / 2) % 1000000007;
	else return v * calc(v, p - 1) % 1000000007;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> n;
	n--;
	long long m = calc(2, 31);
	long long res = calc(m, n);
	cout << res % 1000000007 << '\n';
	return 0;
}