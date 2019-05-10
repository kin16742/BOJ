#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int t, p[10000], a, b;
vector<vector<int>> v;
bool visit[10000];

struct node {
	int m, s;
};

int BFS(int m) {
	visit[m] = 1;
	queue<node> q;
	q.push({ m, 0 });

	while (!q.empty()) {
		int now = q.front().m;
		int S = q.front().s;
		q.pop();

		if (now == b) return S;

		for (int i = 0; i < v[now].size(); i++) {
			if (!visit[v[now][i]]) {
				visit[v[now][i]] = 1;
				q.push({ v[now][i], S + 1 });
			}
		}
	}
	return -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int range = sqrt(10000);
	for (int i = 2; i <= range; i++) {
		if (p[i] == 1) continue;
		for (int j = i + i; j < 10000; j += i) {
			p[j] = 1;
		}
	}

	v.resize(10000);
	for (int i = 1000; i < 10000; i++) {
		if (p[i] == 0) {
			for (int j = 1; j <= 9; j++) {
				if (i + j < 10000 && i / 10 == (i + j) / 10) {
					if (p[i + j] == 0) {
						v[i].push_back(i + j);
						v[i + j].push_back(i);
					}
				}
				if (i + 10 * j < 10000 && i / 100 == (i + 10 * j) / 100) {
					if (p[i + 10 * j] == 0) {
						v[i].push_back(i + 10 * j);
						v[i + 10 * j].push_back(i);
					}
				}
				if (i + 100 * j < 10000 && i / 1000 == (i + 100 * j) / 1000) {
					if (p[i + 100 * j] == 0) {
						v[i].push_back(i + 100 * j);
						v[i + 100 * j].push_back(i);
					}
				}
				if (i + 1000 * j < 10000) {
					if (p[i + 1000 * j] == 0) {
						v[i].push_back(i + 1000 * j);
						v[i + 1000 * j].push_back(i);
					}
				}
			}
		}
	}

	cin >> t;
	while (t--) {
		memset(visit, 0, sizeof(visit));
		cin >> a >> b;
		int res = BFS(a);
		if (res == -1) cout << "Impossible\n";
		else cout << res << '\n';
	}
	return 0;
}