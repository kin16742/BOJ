#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, t;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (1) {
		cin >> t;
		if (!t) break;

		if (t%n == 0) printf("%d is a multiple of %d.\n", t, n);
		else printf("%d is NOT a multiple of %d.\n", t, n);
	}
	return 0;
}