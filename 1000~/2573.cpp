#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a[305][305], b[305][305], s = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visit[305][305];

void DFS(int a, int b) {
	visit[a][b] = 0;

	for (int i = 0; i < 4; i++) {
		if (a + dx[i] < n - 1 && a + dx[i] > 0 && b + dy[i] < m - 1 && b + dy[i] > 0) {
			if (visit[a + dx[i]][b + dy[i]] == 1) DFS(a + dx[i], b + dy[i]);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(a, 0, sizeof(a));
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) a[i][j] = 0;
		}
	}

	while (1) {
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0) visit[i][j] = 1;
				else visit[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] == 1) {
					DFS(i, j);
					cnt++;
				}
			}
		}

		if (cnt > 1) {
			cout << s << '\n';
			break;
		}
		else if (cnt == 0) {
			cout << 0 << '\n';
			break;
		}
		else {
			memcpy(b, a, sizeof(a));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (b[i][j] != 0) {
						for (int k = 0; k < 4; k++) {
							if (i + dx[k] < n && i + dx[k] >= 0 && j + dy[k] < m && j + dy[k] >= 0) {
								if (b[i + dx[k]][j + dy[k]] == 0) {
									a[i][j]--;
								}
							}
						}
						if (a[i][j] < 0) a[i][j] = 0;
					}
				}
			}
		}
		s++;
	}

	return 0;
}