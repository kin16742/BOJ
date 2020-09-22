#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a, b, c, fir, las, di[1001];
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
	cin >> n >> m;
	g.resize(n + 1);
	memset(di, -1, sizeof(di));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b, c });
	}
	cin >> fir >> las;
	djikstra(fir);
	cout << di[las] << '\n';
	return 0;
}