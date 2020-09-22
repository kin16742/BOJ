#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int a, b, dd[55][55], visit[55][55], sum;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int bfs(int x, int y) {
	queue<pair<int, int>> q;

	q.push({ x,y });

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		if (visit[nowx][nowy] == 0) {
			visit[nowx][nowy] = 1;
			for (int i = 0; i < 8; i++) {
				int nextx = nowx + dx[i];
				int nexty = nowy + dy[i];
				if (nextx >= 0 && nextx < b && nexty >= 0 && nexty < a) {
					if (visit[nextx][nexty] == 0) q.push({ nextx,nexty });
				}
			}
		}
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
		sum = 0;
		memset(dd, 0, sizeof(dd));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				cin >> dd[i][j];
				if (dd[i][j] == 0) visit[i][j] = 1;
			}
		}
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				if (visit[i][j] == 0) sum += bfs(i, j);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}

