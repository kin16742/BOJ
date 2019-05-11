#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, a, b, c, t[101][101];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (i != j) t[i][j] = 2000000000;
		
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		t[a][b] = min(c, t[a][b]);
	}

	for (int r = 1; r <= n; r++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				t[i][j] = min(t[i][j], t[i][r] + t[r][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (t[i][j] != 2000000000) cout << t[i][j] << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
	return 0;
}