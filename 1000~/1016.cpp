#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll r[1000001], p[10000];
ll a, b, cnt;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;

	for (ll i = 2; i*i <= b; i++) {
		ll x = a / (i * i);
		if (x*(i*i) < a) x++;
		while (x*(i*i) <= b) {
			r[x*(i*i) - a] = 1;
			x++;
		}
	}
	for (int i = 0; i <= b - a; i++) {
		if (r[i] == 0) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}