#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, s, d, u, v, p, a[505][505], di[505];

void djikstra(int x) {
	memset(di, -1, sizeof(di));
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int nowP = pq.top().second;
		int nowC = -pq.top().first;
		pq.pop();
		if (di[nowP] != -1) continue;
		di[nowP] = nowC;
		for (int i = 0; i < n; i++) {
			if (a[nowP][i] == -1) continue;
			if (di[i] != -1) continue;
			pq.push({ -nowC - a[nowP][i],i });
		}
	}
}
void erase(int y) {
	queue<int> q;
	q.push(y);
	while (!q.empty()) {
		int nowP = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (di[nowP] == di[i] + a[i][nowP] && a[i][nowP] != -1) {
				a[i][nowP] = -1;
				q.push(i);
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		memset(a, -1, sizeof(a));
		cin >> s >> d;
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> p;
			a[u][v] = p;
		}
		djikstra(s);
		erase(d);
		djikstra(s);
		cout << di[d] << '\n';
	}
	return 0;
}