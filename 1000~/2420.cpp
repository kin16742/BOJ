#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, a, b;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
		cin >> a >> b;
    n = abs(a - b);
		cout << n << '\n';
	return 0;
}

