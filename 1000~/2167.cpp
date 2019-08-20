#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t, a1, a2, b1, b2;
int a[400][400];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> t;
	while (t--) {
		int temp = 0;
		cin >> a1 >> b1 >> a2 >> b2;
		for (int i = a1; i <= a2; i++) {
			for (int j = b1; j <= b2; j++) {
				temp += a[i][j];
			}
		}
		cout << temp << '\n';
	}
}