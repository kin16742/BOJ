#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, a, y, m;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		y += a / 30 + 1;
		m += a / 60 + 1;
	}
	y *= 10;
	m *= 15;
	if (y < m) printf("Y %d\n", y);
	else if (y > m) printf("M %d\n", m);
	else printf("Y M %d\n", y, m);
	return 0;
}