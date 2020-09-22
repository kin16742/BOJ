#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char miro[101][101];
int moveX[4] = {1, 0, 0, -1};
int moveY[4] = {0, 1, -1, 0};

struct point {
	int x;
	int y;
	int s;
};

int BFS(int ax, int ay, int dx, int dy) {
	miro[ax][ay] = '0';
	queue<point> q;
	q.push({ ax, ay, 1 });
	while (!q.empty()) {
		int nowX = q.front().x;
		int nowY = q.front().y;
		int nowS = q.front().s;
		q.pop();

		if (nowX == dx && nowY == dy) return nowS;

		for (int i = 0; i < 4; i++) {
			int nextX = nowX + moveX[i];
			int nextY = nowY + moveY[i];

			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
				if (miro[nextY][nextX] == '1') {
					miro[nextY][nextX] = '0';
					if (nextX == dx && nextY == dy) return (nowS + 1);
					q.push({ nextX, nextY, nowS + 1 });
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
			cin >> miro[i][j];
		}
	}
	int ans = BFS(0, 0, m - 1, n - 1);
	cout << ans << '\n';
	return 0;
}