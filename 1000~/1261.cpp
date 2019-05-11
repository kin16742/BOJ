#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a[105][105], di[105][105];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char c;
priority_queue<pair<int, pair<int, int>>> pq;

void djikstra(int x, int y) {
	pq.push({ -a[y][x],{ x,y } });
	while (!pq.empty()) {
		int nowX = pq.top().second.first;
		int nowY = pq.top().second.second;
		int nowC = -pq.top().first;
		pq.pop();
		if (di[nowY][nowX] != -1) continue;
		di[nowY][nowX] = nowC;
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];

			if (nextX < n && nextY < m && nextX >= 0 && nextY >= 0) {
				int nextC = a[nextY][nextX] + nowC;
				if (di[nextY][nextX] == -1) pq.push({ -nextC,{ nextX, nextY } });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	memset(di, -1, sizeof(di));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == '1') a[i][j] = 1;
		}
	}
	djikstra(0, 0);
	cout << di[m - 1][n - 1] << '\n';
	return 0;
}