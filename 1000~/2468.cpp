#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, cnt, res, maxH, A[105][105];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visit[105][105], temp[105][105];

void DFS(int _i, int _j, int _h) {
	temp[_i][_j] = 1;

	for (int i = 0; i < 4; i++) {
		int nextI = _i + dx[i];
		int nextJ = _j + dy[i];

		if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < n) {
			if (!temp[nextI][nextJ] && A[nextI][nextJ] > _h) {
				DFS(nextI, nextJ, _h);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			maxH = max(maxH, A[i][j]);
		}
	}
	for (int h = 0; h <= maxH; h++) {
		cnt = 0;
		memcpy(temp, visit, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!temp[i][j] && A[i][j] > h) {
					DFS(i, j, h);
					cnt++;
					res = max(cnt, res);
				}
			}
		}
	}
	cout << res << '\n';
	return 0;
}