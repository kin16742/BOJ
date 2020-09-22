#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int v, e, k, a, b, c, di[20001];
vector<vector<pair<int, int>>> g;
priority_queue<pair<int, int>> pq;

void djikstra(int s) {
	pq.push({ 0,s });
	while (!pq.empty()) {
		int nowP = pq.top().second;
		int nowC = -pq.top().first;
		pq.pop();
		if (di[nowP] != -1) continue;
		di[nowP] = nowC;
		for (int i = 0; i < g[nowP].size(); i++) {
			int nextP = g[nowP][i].first;
			int nextC = g[nowP][i].second + nowC;
			if (di[nextP] == -1) pq.push({ -nextC,nextP });
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e >> k;
	g.resize(v + 1);
	memset(di, -1, sizeof(di));
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b, c });
	}
	djikstra(k);
	for (int i = 1; i <= v; i++) {
		if (di[i] == -1) cout << "INF" << '\n';
		else cout << di[i] << '\n';
	}
	return 0;
}