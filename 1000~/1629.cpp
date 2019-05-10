#include <iostream>
#include <algorithm>
using namespace std;

long long int a, b, c;

long long int doThat(long long int n, long long int k) {
	if (k == 0) return 1;
	long long int temp = doThat(n, k / 2);
	long long int res = temp * temp % c;
	if (k % 2) res = res * n%c;
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	cout << doThat(a, b) << '\n';
	return 0;
}