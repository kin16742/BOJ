#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int ni, nj, w, h, cnt, bang[20][20], temp[20][20], dist[21][21], cleaned, len, minLen;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char c;

struct node {
	int i, j;
};

struct point {
	int i, j, s;
};

vector<node> dirt;
vector<int> list;

void BFS(int f) {
	memcpy(temp, bang, sizeof(bang));
	temp[dirt[f].i][dirt[f].j] = 1;
	queue<point> q;
	q.push({ dirt[f].i, dirt[f].j, 0 });

	while (!q.empty()) {
		int nowI = q.front().i;
		int nowJ = q.front().j;
		int S = q.front().s;
		q.pop();

		for (int k = 0; k < dirt.size(); k++) {
			if (nowI == dirt[k].i && nowJ == dirt[k].j && k != f) {
				dist[f][k] = S;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nextI = nowI + dx[i];
			int nextJ = nowJ + dy[i];

			if (nextI >= 0 && nextI < h&&nextJ >= 0 && nextJ < w) {
				if (temp[nextI][nextJ] == 0 || temp[nextI][nextJ] == 2) {
					temp[nextI][nextJ] = 1;
					q.push({ nextI, nextJ, S + 1 });
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (1) {
		memset(bang, 0, sizeof(bang));
		memset(dist, -1, sizeof(dist));
		memset(temp, 0, sizeof(temp));
		cnt = 0;
		minLen = 2000000000;

		cin >> w >> h;
		
		if (w == 0 && h == 0) break;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> c;
				if (c == 'x') bang[i][j] = 3;
				else if (c == 'o') {
					dirt.insert(dirt.begin(), { i,j });
					list.push_back(cnt++);
				}
				else if (c == '*') {
					bang[i][j] = 2;
					dirt.push_back({ i, j });
					list.push_back(cnt++);
				}
			}
		}
		for (int i = 0; i < cnt; i++) {
			BFS(i);
		}
		bool rep = false;
		do {
			if (list[0] != 0) break;
			
			len = 0;

			for (int i = 0; i < cnt - 1; i++) {
				if (len == -1) {
					rep = true;
					break;
				}
				len += dist[list[i]][list[i + 1]];
			}
			if (rep) break;

			minLen = min(len, minLen);

		} while (next_permutation(list.begin(), list.end()));

		if (rep) cout << -1 << '\n';
		else cout << minLen << '\n';

		list.clear();
		dirt.clear();
	}
	return 0;
}