#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, map[50][50], temp[50][50], len;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char c;
struct node {
	int i, j, step;
};
void BFS(int _i, int _j) {
	temp[_i][_j] = 0;
	queue<node> q;
	q.push({ _i, _j, 0 });
	while (!q.empty()) {
		int nowI = q.front().i;
		int nowJ = q.front().j;
		int S = q.front().step;
		q.pop();
		len = max(len, S);
		for (int i = 0; i < 4; i++) {
			int nextI = nowI + dx[i];
			int nextJ = nowJ + dy[i];

			if (nextI >= 0 && nextI < n&&nextJ >= 0 && nextJ < m) {
				if (temp[nextI][nextJ] == 1) {
					temp[nextI][nextJ] = 0;
					q.push({ nextI,nextJ,S + 1 });
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == 'W') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	memcpy(temp, map, sizeof(map));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				BFS(i,j);
				memcpy(temp, map, sizeof(map));
			}
		}
	}
	cout << len << '\n';
	return 0;
}
