#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int m, n, k, x, y, cnt;
int graph[105][105];
bool DFSvisit[105][105];
int trash[10000];

void DFS(int a, int b) {
	DFSvisit[a][b] = false;
	trash[cnt]++;

	if (DFSvisit[a][b + 1] == true) DFS(a, b + 1);
	if (DFSvisit[a][b - 1] == true) DFS(a, b - 1);
	if (DFSvisit[a + 1][b] == true) DFS(a + 1, b);
	if (DFSvisit[a - 1][b] == true) DFS(a - 1, b);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	memset(graph, 0, sizeof(graph));
	memset(DFSvisit, 0, sizeof(DFSvisit));
	memset(trash, 0, sizeof(trash));

	while (k--) {
		cin >> x >> y;
		graph[y + 1][x + 1] = 1;
		DFSvisit[y + 1][x + 1] = true;
	}

	for (int i = 0; i <= 104; i++) {
		for (int j = 0; j <= 104; j++) {
			if (DFSvisit[i][j] == true) {
				DFS(i, j);
				cnt++;
			}
		}
	}

	sort(trash, trash + cnt);
	cout << trash[cnt - 1] << '\n';

	return 0;
}