#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int m, n, tomato[1005][1005], day;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct node {
	int i, j;
};
struct point {
	int i, j, s;
};
vector<node> isT;

void BFS() {
	queue<point> q;
	for (int k = 0; k < isT.size(); k++) {
		q.push({ isT[k].i, isT[k].j, 0 });
	}

	while (!q.empty()) {
		int nowI = q.front().i;
		int nowJ = q.front().j;
		int S = q.front().s;
		q.pop();
		day = max(S, day);

		for (int i = 0; i < 4; i++) {
			int nextI = nowI + dx[i];
			int nextJ = nowJ + dy[i];

			if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m) {
				if (tomato[nextI][nextJ] == 0) {
					tomato[nextI][nextJ] = 1;
					q.push({ nextI, nextJ, S + 1 });
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) isT.push_back({ i, j });
		}
	}
	BFS();
	bool b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				b = 1;
			}
		}
	}
	if (b) cout << -1 << '\n';
	else cout << day << '\n';
	return 0;
}
