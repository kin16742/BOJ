#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, u, v, w, M, x, S, y, dM[10005], dS[10005];
vector<vector<pair<int, int>>> g;
priority_queue<pair<int, int>> pq1, pq2;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
		g[v].push_back({ u,w });
	}
	for (int i = 0; i <= n; i++) {
		dM[i] = 2000000000;
		dS[i] = 2000000000;
	}
	cin >> M >> x;
	for (int i = 0; i < M; i++) {
		cin >> u;
		pq1.push({ 0,u });
	}
	while (!pq1.empty()) {
		int nowP = pq1.top().second;
		int nowC = -pq1.top().first;
		pq1.pop();
		if (dM[nowP] >= nowC) dM[nowP] = nowC;
		for (int i = 0; i < g[nowP].size(); i++) {
			int nextP = g[nowP][i].first;
			int nextC = nowC + g[nowP][i].second;
			if (dM[nextP] >= nextC && nextC <= x) pq1.push({ -nextC,nextP });
		}
	}
	cin >> S >> y;
	for (int i = 0; i < S; i++) {
		cin >> u;
		pq2.push({ 0,u });
	}
	while (!pq2.empty()) {
		int nowP = pq2.top().second;
		int nowC = -pq2.top().first;
		pq2.pop();
		if (dS[nowP] >= nowC) dS[nowP] = nowC;
		for (int i = 0; i < g[nowP].size(); i++) {
			int nextP = g[nowP][i].first;
			int nextC = nowC + g[nowP][i].second;
			if (dS[nextP] >= nextC && nextC <= y) pq2.push({ -nextC,nextP });
		}
	}
	int res = 2000000000;
	for (int i = 1; i <= n; i++) {
		if (dM[i] != 0 && dS[i] != 0 && dM[i] <= x && dS[i] <= y) {
			res = min(res, dM[i] + dS[i]);
		}
	}
	if (res == 2000000000) res = -1;
	cout << res << '\n';
	return 0;
}