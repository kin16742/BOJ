#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int a, b;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	for (int i = 3; i <= 3000; i++) {
		for (int j = 1; j <= i; j++) {
			if ((i + j) * 2 - 4 == a && (i - 2) * (j - 2) == b) {
				cout << i << ' ' << j << '\n';
				break;
			}
		}
	}
	return 0;
}