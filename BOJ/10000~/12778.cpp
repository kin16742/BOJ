#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int t, m, tempi;
char c, tempc;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> m >> c;
		if (c == 'C') {
			for (int i = 0; i < m; i++) {
				cin >> tempc;
				cout << (int)(tempc - 'A' + 1) << ' ';
			}
			cout << '\n';
		}
		else {
			for (int i = 0; i < m; i++) {
				cin >> tempi;
				cout << (char)(tempi + 'A' - 1) << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}