#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a, b, c, t[501][501];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			cin >> a;
			t[i][j] = a;
		}
	}

	for (int r = 1; r <= n; r++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (t[i][j] > t[i][r] + t[r][j])
					t[i][j] = t[i][r] + t[r][j];

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (t[a][b] <= c) cout << "Enjoy other party\n";
		else cout << "Stay here\n";
	}

	return 0;
}