#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, cnt = 2, temp[101][101], map[101][101], bridge = 1000;

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

struct node {
	int x, y, len;
};

void DFS(int y, int x) {
	map[y][x] = cnt;

	for (int i = 0; i < 4; i++) {
		int nextX = x + moveX[i];
		int nextY = y + moveY[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
			if(map[nextY][nextX] == 1) DFS(nextY, nextX);
		}
	}
}

void BFS(int d) {
	queue<node> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(map[i][j] == d) q.push({ j , i , 0 });
		}
	}

	while (!q.empty()) {
		int X = q.front().x;
		int Y = q.front().y;
		int L = q.front().len;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = X + moveX[i];
			int nextY = Y + moveY[i];

			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
				if (temp[nextY][nextX] != d && temp[nextY][nextX] != 0)
					bridge = min(bridge, L);
			}
		}

		for (int i = 0; i < 4; i++) {
			int nextX = X + moveX[i];
			int nextY = Y + moveY[i];

			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
				if (temp[nextY][nextX] == 0) {
					temp[nextY][nextX] = d;
					q.push({ nextX, nextY, L + 1 });
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				DFS(i, j);
				cnt++;
			}
		}
	}
	for (int i = 2; i <= cnt; i++) {
		memcpy(temp, map, sizeof(map));
		BFS(i);
	}
	cout << bridge << '\n';
	return 0;
}