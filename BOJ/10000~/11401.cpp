#include <iostream>
#include <algorithm>
using namespace std;

long long int a, b;
long long int f[4000001];

long long int doThat(long long int n, long long int k) {
	if (k == 0) return 1;
	long long int temp = doThat(n, k / 2);
	long long int res = temp * temp % 1000000007;
	if (k % 2) res = res * n % 1000000007;
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	f[0] = f[1] = 1;
	for (int i = 2; i <= a; i++) {
		f[i] = (f[i - 1] * i) % 1000000007;
	}
	cout << ((f[a] * doThat(f[b], 1000000005)) % 1000000007 * doThat(f[a - b], 1000000005)) % 1000000007 << '\n';

	return 0;
}