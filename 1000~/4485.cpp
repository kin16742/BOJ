#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a[126][126], di[126][126], cnt = 1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
priority_queue<pair<int, pair<int, int>>> pq;

void djikstra(int x, int y) {
	pq.push({ -a[y][x],{x,y} });
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

			if (nextX < n && nextY < n && nextX >= 0 && nextY >= 0) {
				int nextC = a[nextY][nextX] + nowC;
				if (di[nextY][nextX] == -1) pq.push({ -nextC,{nextX, nextY} });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n == 0) break;
		memset(a, 0, sizeof(a));
		memset(di, -1, sizeof(di));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		djikstra(0, 0);
		printf("Problem %d: %d\n", cnt++, di[n - 1][n - 1]);
	}
	return 0;
}