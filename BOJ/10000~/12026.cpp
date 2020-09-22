#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a[1010], di[1010];
char c;
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

	memset(di, -1, sizeof(di));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'B') a[i] = 0;
		if (c == 'O') a[i] = 1;
		if (c == 'J') a[i] = 2;
	}
	g.resize(n + 1);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] == (a[i] + 1) % 3) {
				g[i].push_back({ j,(j - i)*(j - i) });
			}
		}
	}
	djikstra(0);
	cout << di[n - 1] << '\n';
	return 0;
}