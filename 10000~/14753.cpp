#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, dd[10001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> dd[i];
	sort(dd, dd + n);
	cout << max(max(dd[0] * dd[1], dd[0] * dd[1] * dd[n - 1]), max(dd[n - 1] * dd[n - 2], dd[n - 1] * dd[n - 2] * dd[n - 3]));
	return 0;
}