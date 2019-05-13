#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, a, b, A = 100, B = 100;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b) B -= a;
		if (b > a) A -= b;
	}
	cout << A << '\n' << B << '\n';
	return 0;

}