#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, k, a, b, c, t[501][501];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++) {
			if(i!=j) t[i][j] = 2000000;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (c == 0) {
			t[a][b] = 0;
			t[b][a] = 1;
		}
		else {
			t[a][b] = 0;
			t[b][a] = 0;
		}
	}
	
	for (int r = 1; r <= n; r++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (t[i][j] > t[i][r] + t[r][j])
					t[i][j] = t[i][r] + t[r][j];
			}
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		cout << t[a][b] << '\n';
	}

	return 0;
}