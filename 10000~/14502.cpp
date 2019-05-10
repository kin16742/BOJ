#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, A[10][10], temp[10][10], visit[10][10], safe, rem;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct point {
	int i, j;
};

vector<point> virus;

void DFS(int _i, int _j) {
	visit[_i][_j] = 2;
	for (int i = 0; i < 4; i++) {
		int nextI = _i + dx[i];
		int nextJ = _j + dy[i]; 

		if (nextI >= 0 && nextI < n&&nextJ >= 0 && nextJ < m) {
			if (!visit[nextI][nextJ]) DFS(nextI, nextJ);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}
	for (int i0 = 0; i0 < n; i0++) {
		for (int j0 = 0; j0 < m; j0++) {
			memcpy(temp, A, sizeof(A));
			if (temp[i0][j0] == 0) {
				temp[i0][j0] = 1;
				for (int i1 = 0; i1 < n; i1++) {
					for (int j1 = 0; j1 < m; j1++) {
						if (temp[i1][j1] == 0) {
							temp[i1][j1] = 1;
							for (int i2 = 0; i2 < n; i2++) {
								for (int j2 = 0; j2 < m; j2++) {
									if (temp[i2][j2] == 0) {
										temp[i2][j2] = 1;
										memcpy(visit, temp, sizeof(temp));
										for (int z = 0; z < virus.size(); z++) {
											DFS(virus[z].i, virus[z].j);
										}
										int cnt = 0;
										for (int i = 0; i < n; i++) {
											for (int j = 0; j < m; j++) {
												if (visit[i][j] == 0) cnt++;
											}
										}
										safe = max(safe, cnt);
										temp[i2][j2] = 0;
									}
								}
							}
							temp[i1][j1] = 0;
						}
					}
				}
				temp[i0][j0] = 0;
			}
		}
	}
	cout << safe << '\n';
	return 0;
}
