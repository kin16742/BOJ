#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a, b, c, t[501][501], co[501], res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			t[i][j] = 2000000;


	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		t[a][b] = 1;
	}

	for (int r = 1; r <= n; r++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (t[i][j] > t[i][r] + t[r][j])
					t[i][j] = t[i][r] + t[r][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (t[i][j] != 2000000) {
				co[i]++;
				co[j]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (co[i] == n - 1) res++;
	}

	cout << res << '\n';

	return 0;
}