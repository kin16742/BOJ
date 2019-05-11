#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, t, res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = n - 1; i >= 1; i--) {
		t += i;
		t %= 45678;
	}
	cout << (1 + 4 * n + 3 * t) % 45678 << '\n';
	return 0;
}