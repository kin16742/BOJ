#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int a[3];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 3; i++) cin >> a[i];
	sort(a, a + 3);
	if (a[1] - a[0] == a[2] - a[1]) {
		cout << 2 * a[2] - a[1] << '\n';
	}
	else if (a[1] - a[0] > a[2] - a[1]) {
		cout << (a[0] + a[1]) / 2 << '\n';
	}
	else if (a[1] - a[0] < a[2] - a[1]) {
		cout << (a[1] + a[2]) / 2 << '\n';
	}
	return 0;
}