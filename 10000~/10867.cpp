#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, num, a[2005];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a[num + 1000] = 1;
	}
	for (int i = 0; i < 2005; i++) {
		if (a[i] != 0) cout << i - 1000 << ' ';
	}
	return 0;
}