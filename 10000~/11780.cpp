#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, k, a, b, c, t[501][501], s[501][501];

void route(vector<int> &v, int x, int y) {
	if (!s[x][y]) {
		v.push_back(x);
		v.push_back(y);
		return;
	}
	route(v, x, s[x][y]);
	v.pop_back();
	route(v, s[x][y], y);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++) {
			if(i != j) t[i][j] = 2000000;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		t[a][b] = min(t[a][b], c);
	}
	
	for (int r = 1; r <= n; r++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (t[i][j] > t[i][r] + t[r][j]){
					t[i][j] = t[i][r] + t[r][j];
					s[i][j] = r;
				}
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << t[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << 0 << '\n';
			else {
				vector<int> v;
				route(v, i, j);
				cout << v.size() << ' ';
				for (int i = 0; i < v.size(); i++) {
					cout << v[i] << ' ';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}