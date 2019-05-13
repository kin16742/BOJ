#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a, b;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
		cout << a + b << '\n';
	}
	return 0;
}

