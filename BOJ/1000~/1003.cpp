#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct fibonacci {
	int call0 = 0;
	int call1 = 0;
};
fibonacci a[41];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt, t;
	cin >> t;
	while (t--) {
		cin >> n;
		a[0].call0 = 1;
		a[1].call1 = 1;
		for (int i = 2; i <= n; i++) {
			a[i].call0 = a[i - 1].call0 + a[i - 2].call0;
			a[i].call1 = a[i - 1].call1 + a[i - 2].call1;
		}
		cout << a[n].call0 << ' ' << a[n].call1 << '\n';
	}
	return 0;
}