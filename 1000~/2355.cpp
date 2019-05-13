#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll a, b;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	
	if (a > b) swap(a, b);

	cout << (b - a + 1)*(a + b) / 2 << '\n';

	return 0;

}