#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, x, a, b, s, di[1001], res;
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
	cin >> n >> m >> x;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> s;
		g[a].push_back({ b, s });
	}
	for (int i = 1; i <= n; i++) {
		int len = 0;

		memset(di, -1, sizeof(di));
		djikstra(i);
		len += di[x];

		memset(di, -1, sizeof(di));
		djikstra(x);
		len += di[i];

		res = max(res, len);
	}
	cout << res << '\n';
	return 0;
}