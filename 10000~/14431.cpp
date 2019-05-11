#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int x1, yy1, x2, y2, n, a, b, di[4010], prime[6000], cnt;
vector<vector<pair<int, int>>> g;
vector<pair<int, int>> p;
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

	cin >> x1 >> yy1 >> x2 >> y2 >> n;
	p.push_back({ x1,yy1 });
	p.push_back({ x2,y2 });
	memset(di, -1, sizeof(di));
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p.push_back({ a,b });
	}
	g.resize(n + 3);

	int range = sqrt(6000);
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i <= range; i++) {
		if (prime[i] != 1) {
			for (int j = i * i; j < 6000; j += i) {
				prime[j] = 1;
			}
		}
	}
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p.size(); j++) {
			int dist = sqrt((p[j].second - p[i].second)*(p[j].second - p[i].second) + (p[j].first - p[i].first)*(p[j].first - p[i].first));
			if (prime[dist] == 0) {
				g[i].push_back({ j,dist });
				g[j].push_back({ i,dist });
			}
		}
	}
	djikstra(0);
	cout << di[1] << '\n';
	return 0;
}