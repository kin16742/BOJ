#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a, b, t, di[1010], fr, mx;
char c;
vector<vector<pair<int, int>>> g;
vector<pair<pair<int, int>,int>> p;
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
		cin >> a >> b >> t;
		p.push_back({ { a,b }, t });
		g[a].push_back({ b,t });
		g[b].push_back({ a,t });
	}
	djikstra(1);
	fr = di[n];
	g.clear();
	for (int i = 0; i < m; i++) {
		g.resize(n + 1);
		memset(di, -1, sizeof(di));
		for (int j = 0; j < m; j++) {
			if (i != j) {
				g[p[j].first.first].push_back({ p[j].first.second,p[j].second });
				g[p[j].first.second].push_back({ p[j].first.first,p[j].second });
			}
		}
		djikstra(1);
		if (di[n] == -1) {
			cout << -1 << '\n';
			return 0;
		}
		else {
			mx = max(mx, di[n] - fr);
		}
		g.clear();
	}
	cout << mx << '\n';
	return 0;
}