#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int t, n, m;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i <= 600;i++) {
			for (int j = 0; j <= 600; j++) {
				if (i + j == m && i + 2 * j == n) {
					cout << i << ' ' << j << '\n';
					break;
				}
			}
		}
	}
	return 0;
}