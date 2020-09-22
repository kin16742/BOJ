#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int t;
double a;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		double b = 0;
		cin >> a;
		for (int i = 0; i < a; i++) {
			b += 0.5;
			b *= 2;
		}
		cout << (ll)b << '\n';
	}
	return 0;
}