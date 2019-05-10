#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, color2[100][100], color3[100][100], cnt2, cnt3;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char c;

void DFS2(int x, int y) {
	int now = color2[y][x];
	color2[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
			if (color2[nextY][nextX] == now) DFS2(nextX, nextY);
		}
	}
}
void DFS3(int x, int y) {
	int now = color3[y][x];
	color3[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
			if (color3[nextY][nextX] == now) DFS3(nextX, nextY);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'R') {
				color2[i][j] = 1;
				color3[i][j] = 1;
			}
			else if (c == 'G') {
				color2[i][j] = 1;
				color3[i][j] = 2;
			}
			else if (c == 'B') {
				color2[i][j] = 2;
				color3[i][j] = 3;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color2[i][j] != 0) {
				DFS2(j, i);
				cnt2++;
			}
			if (color3[i][j] != 0) {
				DFS3(j, i);
				cnt3++;
			}
		}
	}
	cout << cnt3 << ' ' << cnt2 << '\n';
	return 0;
}