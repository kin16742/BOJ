#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int t, n, cnt;
int e[3000][3];
vector<vector<int>> graph;
vector<bool> visit;

void DFS(int s) {
	visit[s] = 1;

	for (int i = 0; i < graph[s].size(); i++) {
		if (!visit[graph[s][i]]) DFS(graph[s][i]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cnt = 0;
		memset(e, 0, sizeof(e));

		cin >> n;
		
		graph.resize(n + 1);
		visit.resize(n + 1);

		for (int i = 0; i < n; i++) {
			cin >> e[i][0] >> e[i][1] >> e[i][2];
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = e[i][0] - e[j][0];
				int y = e[i][1] - e[j][1];
				double r = (double)e[i][2] + (double)e[j][2];
				double d = sqrt(x * x + y * y);

				if (d <= r) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				DFS(i);
				cnt++;
			}
		}
		cout << cnt << '\n';

		graph.clear();
		visit.clear();
	}
	return 0;
}