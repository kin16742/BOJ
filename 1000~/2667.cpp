#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int n, cnt;
char house[26][26];
bool visit[27][27];
int danzi[320];

void DFS(int a, int b) {
	visit[a][b] = true;
	danzi[cnt]++;

	if (visit[a][b + 1] == false) DFS(a, b + 1);
	if (visit[a][b - 1] == false) DFS(a, b - 1);
	if (visit[a + 1][b] == false) DFS(a + 1, b);
	if (visit[a - 1][b] == false) DFS(a - 1, b);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(visit, 1, sizeof(visit));
	memset(house, 0, sizeof(house));

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
			if (house[i][j] == '1') visit[i][j] = false;
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (visit[i][j] == false) {
				DFS(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
	sort(danzi, danzi + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << danzi[i] << endl;
	}

	return 0;
}
