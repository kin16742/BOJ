#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int m, n, k, x_1, x_2, y_1, y_2, cnt;
int graph[105][105];
bool DFSvisit[105][105];
int space[10000];

void DFS(int a, int b) {
	DFSvisit[a][b] = false;
	space[cnt]++;

	if (b + 1 < n && DFSvisit[a][b + 1] == true) DFS(a, b + 1);
	if (b - 1 >= 0 && DFSvisit[a][b - 1] == true) DFS(a, b - 1);
	if (a + 1 < m && DFSvisit[a + 1][b] == true) DFS(a + 1, b);
	if (a - 1 >= 0 && DFSvisit[a - 1][b] == true) DFS(a - 1, b);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> k;

	memset(graph, 0, sizeof(graph));
	memset(DFSvisit, 1, sizeof(DFSvisit));
	memset(space, 0, sizeof(space));

	while (k--) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int i = y_1; i < y_2; i++) {
			for (int j = x_1; j < x_2; j++) {
				DFSvisit[i][j] = false;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (DFSvisit[i][j] == true) {
				DFS(i, j);
				cnt++;
			}
		}
	}

	sort(space, space + cnt);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << space[i] << ' ';
	}
	if (cnt) cout << '\n';
	return 0;
}
