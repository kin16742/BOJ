#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int t, m, n, k, x, y, cnt;
int graph[55][55];
bool DFSvisit[55][55];

void DFS(int a, int b) {
	DFSvisit[a][b] = false;

	if (DFSvisit[a][b + 1] == true) DFS(a, b + 1);
	if (DFSvisit[a][b - 1] == true) DFS(a, b - 1);
	if (DFSvisit[a + 1][b] == true) DFS(a + 1, b);
	if (DFSvisit[a - 1][b] == true) DFS(a - 1, b);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> m >> n >> k;

		memset(graph, 0, sizeof(graph));
		memset(DFSvisit, 0, sizeof(DFSvisit));

		while (k--) {
			cin >> x >> y;
			graph[y + 1][x + 1] = 1;
			DFSvisit[y + 1][x + 1] = true;
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (DFSvisit[i][j] == true) {
					DFS(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
}
