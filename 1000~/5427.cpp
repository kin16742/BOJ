#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int t, w, h, x, y, map[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char c;
struct node {
	int i, j;
};
struct point {
	int i, j, s;
};

vector<node> fire;

int BFS(int _i, int _j) {
	map[_i][_j] = 1;
	queue<point> q;
	q.push({ _i, _j, 1 });
	
	while (!q.empty()) {
		int nowI = q.front().i;
		int nowJ = q.front().j;
		int S = q.front().s;
		q.pop();
		if (q.empty()) {
			for (int i = 0; i < fire.size(); i++) {
				q.push({ fire[i].i, fire[i].j, -1 });
			}
			fire.clear();
		}
		int nextI, nextJ;
		if (S == -1) {
			for (int i = 0; i < 4; i++) {
				nextI = nowI + dx[i];
				nextJ = nowJ + dy[i];

				if (nextI >= 0 && nextI < h && nextJ >= 0 && nextJ < w) {
					if (map[nextI][nextJ] != 3 && map[nextI][nextJ] != 2) {
						map[nextI][nextJ] = 2;
						fire.push_back({ nextI, nextJ });
					}
				}
			}
		}
		if (!q.empty()) {
			if (S == -1 && q.front().s != -1) {
				for (int i = 0; i < fire.size(); i++) {
					q.push({ fire[i].i, fire[i].j, -1 });
				}
				fire.clear();
			}
		}
		if (map[nowI][nowJ] != 2) {
			for (int i = 0; i < 4; i++) {
				nextI = nowI + dx[i];
				nextJ = nowJ + dy[i];
				if (nextI < 0 || nextI >= h || nextJ < 0 || nextJ >= w) return S;			
				else {
					if (map[nextI][nextJ] == 0) {
						map[nextI][nextJ] = 1;
						q.push({ nextI, nextJ, S + 1 });
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		fire.clear();
		memset(map, 0, sizeof(map));
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> c;
				if (c == '@') {
					x = j;
					y = i;
				}
				else if (c == '*') {
					map[i][j] = 2;
					fire.push_back({ i, j });
				}
				else if (c == '#') map[i][j] = 3;
			}
		}
		int ans = BFS(y, x);
		if (ans == -1) cout << "IMPOSSIBLE" << '\n';
		else cout << ans << '\n';
	}
	return 0;
}