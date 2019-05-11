#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a, b, c, t[55][55], res[55];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 55; i++)
		for (int j = 0; j < 55; j++)
			t[i][j] = 2000000;

	cin >> n;

	while(1){
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		t[a][b] = 1;
		t[b][a] = 1;
	}

	for (int r = 1; r <= n; r++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if(t[i][j] > t[i][r] + t[r][j])
					t[i][j] = t[i][r] + t[r][j];

	int mx = 1000000;
	memset(res, 0, sizeof(res));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			res[i] = max(res[i], t[i][j]);
		}
		mx = min(mx, res[i]);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (res[i] == mx) cnt++;
	}
	cout << mx << ' ' << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (res[i] == mx) cout << i << ' ';
	}
	cout << '\n';
	return 0;
}