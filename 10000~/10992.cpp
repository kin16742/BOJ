#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, l, a[2001], res = 0, num;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) cout << ' ';
		cout << '*';
		if (i == n && i != 1) {
			for (int j = 1; j <= i * 2 - 2; j++) cout << '*';
		}
		else {
			for (int j = 1; j <= (i - 1) * 2 - 1; j++) cout << ' ';
			if (i > 1) cout << '*';
		}
		cout << endl;
	}

	return 0;
}