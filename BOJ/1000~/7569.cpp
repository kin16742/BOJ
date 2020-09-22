#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int m, n, h, tomato[105][105][105], day;
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 0, 0, 0, 0, 1, -1 };
int dh[6] = { 1, -1, 0, 0, 0, 0 };

struct node {
	int i, j, k;
};
struct point {
	int i, j, k, s;
};
vector<node> isT;

void BFS() {
	queue<point> q;
	for (int z = 0; z < isT.size(); z++) {
		q.push({ isT[z].i, isT[z].j, isT[z].k, 0 });
	}

	while (!q.empty()) {
		int nowI = q.front().i;
		int nowJ = q.front().j;
		int nowK = q.front().k;
		int S = q.front().s;
		q.pop();
		day = max(S, day);

		for (int i = 0; i < 6; i++) {
			int nextI = nowI + dx[i];
			int nextJ = nowJ + dy[i];
			int nextK = nowK + dh[i];

			if (nextK >=0 && nextK < h && nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m) {
				if (tomato[nextI][nextJ][nextK] == 0) {
					tomato[nextI][nextJ][nextK] = 1;
					q.push({ nextI, nextJ, nextK, S + 1 });
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) isT.push_back({ i, j, k });
			}
		}
	}
	BFS();
	bool b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (tomato[i][j][k] == 0) {
					b = 1;
				}
			}
		}
	}
	if (b) cout << -1 << '\n';
	else cout << day << '\n';
	return 0;
}
