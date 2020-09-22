#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, a[1000], m, cnt;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < n; i++) {
		cnt += a[i] / m;
		if (a[i] % m != 0) cnt++;
	}
	cout << cnt * m << '\n';
	return 0;
}