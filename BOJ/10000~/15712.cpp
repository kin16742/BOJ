#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

long long A, R, N, mod, res;

long long mpow(long long v, long long p) {
	if (p == 0) return 1;
	if (p % 2 == 0) return mpow(v * v % mod, p / 2) % mod;
	else return v * mpow(v, p - 1) % mod;
}

long long calc(long long r, long long n) {
	if (n == 1) return 1;
	if (n % 2 == 0) return (((1 + r) % mod) * (calc(r * r % mod, n / 2) % mod)) % mod;
	else return ((mpow(r, n - 1) % mod) + (calc(r, n - 1) % mod)) % mod;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> R >> N >> mod;
	res = A * calc(R, N) % mod;
	cout << res << '\n';
	return 0;
}