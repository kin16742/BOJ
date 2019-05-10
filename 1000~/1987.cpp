#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int r, c, cnt, A[25][25];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
char ch;
bool visit[26];

void DFS(int _i, int _j, int s) {
	visit[A[_i][_j] - 'A'] = 1;
	cnt = max(cnt, s);

	for (int i = 0; i < 4; i++) {
		int nextI = _i + dx[i];
		int nextJ = _j + dy[i];

		if (nextI >= 0 && nextI < r && nextJ >= 0 && nextJ < c) {
			if (!visit[A[nextI][nextJ] - 'A']) {
				DFS(nextI, nextJ, s + 1);
				visit[A[nextI][nextJ] - 'A'] = 0;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> ch;
			A[i][j] = ch;
		}
	}
	DFS(0, 0, 1);
	cout << cnt << '\n';
	return 0;
}