#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, di[150000], ro[150000], res[150000], cnt;
vector<vector<pair<int, int>>> g;
priority_queue<pair<pair<int, int>, int>> pq;

void djikstra(int x, int y) {
	pq.push({ {0, x}, -1 });
	while (!pq.empty()) {
		int nowP = pq.top().first.second;
		int nowC = -pq.top().first.first;
		int prev = pq.top().second;
		pq.pop();
		if (di[nowP] != -1) continue;
		di[nowP] = nowC;
		if (prev != -1) ro[nowP] = prev;
		if (nowP == y) break;
		if (nowP + 1 <= 100000 && di[nowP + 1] == -1) pq.push({ {-(nowC + 1),nowP + 1},nowP });
		if (nowP - 1 >= 0 && di[nowP - 1] == -1)	  pq.push({ {-(nowC + 1),nowP - 1},nowP });
		if (nowP * 2 <= 100000 && di[nowP * 2] == -1) pq.push({ {-(nowC + 1),nowP * 2},nowP });
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	memset(di, -1, sizeof(di));
	djikstra(n, m);
	cout << di[m] << '\n';
	res[cnt++] = m;
	while (ro[m] != 0) {
		res[cnt++] = ro[m];
		m = ro[m];
	}
	if (m != n) res[cnt++] = n;
	for (int i = cnt - 1; i >= 0; i--) cout << res[i] << ' ';
	cout << '\n';
	return 0;
}