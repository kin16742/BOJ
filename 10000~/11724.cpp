#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> DFSvisit;
int n, m, u, v, cnt;

void DFS(int s) {
	DFSvisit[s] = true;

	for (int i = 0; i < graph[s].size(); i++) {
		int next = graph[s][i];
		if (DFSvisit[next] == false) DFS(next);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	graph.resize(n + 1);
	DFSvisit.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (DFSvisit[i] == false) {
			DFS(i);
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}