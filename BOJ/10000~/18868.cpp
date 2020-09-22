#include <iostream>
using namespace std;

int m, n, res;
int a[15][105];
int b[15][105];

int main() {
	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			for (int k = 1; k < n; k++) {
				int cnt = 0;
				for (int w = k + 1; w <= n; w++) {
					if (a[i][k] < a[i][w] && a[j][k] < a[j][w]) cnt++;
					if (a[i][k] == a[i][w] && a[j][k] == a[j][w]) cnt++;
					if (a[i][k] > a[i][w] && a[j][k] > a[j][w]) cnt++;
				}
				if (cnt == n - 1) res++;
			}
		}
	}
	cout << res << '\n';
}