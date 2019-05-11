#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	ll res = 0, p = 1;
	while (n != 0) {
		if (n & 1) {
			res += p;
		}

		p *= 3;
		n >>= 1;
	}
	cout << res << '\n';
	return 0;
}