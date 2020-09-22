#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int t, n, cnt, A;
int visit[1001];
vector<vector<int>> graph;

void DFS(int s) {
	visit[s]++;
	if (!visit[graph[s][0]]) DFS(graph[s][0]);
	else cnt++;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		cin >> n;
		graph.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> A;
			if (i == A) cnt++;
			else graph[i].push_back(A);
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 && graph[i].size() > 0) DFS(i);
		}
		cout << cnt << '\n';
		graph.clear();
	}
	return 0;
}