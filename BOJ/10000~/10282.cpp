#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int t, n, d, c, a, b, s, di[10001];
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
	cin >> t;
	while (t--) {
		cin >> n >> d >> c;
		g.resize(n + 1);
		memset(di, -1, sizeof(di));
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			g[b].push_back({ a, s });
		}
		djikstra(c);
		int cnt = 0, mx = 0;
		for (int i = 1; i <= n; i++) {
			if (di[i] != -1) {
				cnt++;
				mx = max(mx, di[i]);
			}
		}
		cout << cnt << ' ' << mx << '\n';
		g.clear();
	}
	return 0;
}