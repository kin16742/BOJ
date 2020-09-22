#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, maxH, cnt;
bool visit[10001];

struct node {
	int n, h;
};

vector<vector<int>> com;
vector<node> hack;

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

	while (m--) {
		cin >> a >> b;
		com[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		DFS(i);
		maxH = max(cnt, maxH);
		hack.push_back({ i, cnt });
	}
	for (int i = 0; i < n; i++) {
		if (hack[i].h != maxH) {
			hack[i].h = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (hack[i].h != -1) cout << hack[i].n << ' ';
	}
	cout << '\n';
	return 0;
}