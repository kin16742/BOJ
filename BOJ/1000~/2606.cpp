#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, cnt = -1;
vector<vector<int>> com;
vector<bool> visit;

void DFS(int s) {
	visit[s] = 1;
	cnt++;
	
	for (int i = 0; i < com[s].size(); i++) {
		if (!visit[com[s][i]]) DFS(com[s][i]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	com.resize(n + 1);
	visit.resize(n + 1);
	while (m--) {
		cin >> a >> b;
		com[a].push_back(b);
		com[b].push_back(a);
	}
	DFS(1);
	cout << cnt << '\n';
	return 0;
}