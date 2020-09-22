#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, e, a, b, c, x, y;
int di[3][805];
vector<vector<pair<int, int>>> g;

void djikstra(int idx, int s) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int nowP = pq.top().second;
		int nowC = -pq.top().first;
		pq.pop();
		if (di[idx][nowP] != -1) continue;
		di[idx][nowP] = nowC;
		for (int i = 0; i < g[nowP].size(); i++) {
			int nextP = g[nowP][i].first;
			int nextC = g[nowP][i].second + nowC;
			if (di[idx][nextP] == -1) pq.push({ -nextC,nextP });
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> e;
	memset(di, -1, sizeof(di));
	g.resize(n + 1);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	cin >> x >> y;
	djikstra(0, 1);
	djikstra(1, x);
	djikstra(2, y);
	int res = 2000000000;
	if (di[0][x] != -1 && di[1][y] != -1 && di[2][n] != -1) res = min(res, di[0][x] + di[1][y] + di[2][n]);
	if (di[0][y] != -1 && di[2][x] != -1 && di[1][n] != -1) res = min(res, di[0][y] + di[2][x] + di[1][n]);
	if (res == 2000000000) res = -1;
	cout << res << '\n';
	return 0;
}