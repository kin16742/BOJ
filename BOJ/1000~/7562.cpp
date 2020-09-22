#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int t, l, xN, yN, xD, yD;
bool visit[301][301];

struct point {
	int x;
	int y;
	int s;
};

int moveX[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int moveY[8] = {2, 1, -2, -1, 2, 1, -2, -1};

int BFS(int sx, int sy, int dx, int dy) {
	visit[sx][sy] = true;

	queue<point> q;

	q.push({ sx, sy, 0 });

	while (!q.empty()) {
		int xx = q.front().x;
		int yy = q.front().y;
		int ss = q.front().s;
		q.pop();

		if (xD == xx && yD == yy) return ss;

		for (int i = 0; i < 8; i++) {
			int nextX = xx + moveX[i];
			int nextY = yy + moveY[i];

			if (nextX >= 0 && nextX < l && nextY >= 0 && nextY < l) {
				if (visit[nextX][nextY] == false) {
					visit[nextX][nextY] = true;
					q.push({ nextX, nextY, ss + 1 });
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> l >> xN >> yN >> xD >> yD;
		int ans = BFS(xN, yN, xD, yD);
		cout << ans << '\n';
		memset(visit,0,sizeof(visit));
	}
	return 0;
}