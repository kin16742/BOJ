#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, cnt = 1, temp, kevin = 1000000, result;
vector<vector<int>> graph;
vector<bool> BFSvisit;
int dist[1000];

void BFS(int s) {
	queue<int> q;
	q.push(s);
	BFSvisit[s] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			if (BFSvisit[next] == false) {
				temp += cnt;
				BFSvisit[next] = true;
				q.push(next);
				dist[next] = dist[here] + 1;
			}
		}
	}
	for (int i = 0; i <= n; i++) temp += dist[i];
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	graph.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		BFSvisit.clear();
		BFSvisit.resize(n + 1);
		memset(dist, 0, sizeof(dist));
		temp = 0;
		cnt = 1;
		BFS(i);
		if (temp < kevin) {
			kevin = min(kevin, temp);
			result = i;
		}
	}

	cout << result << '\n';

	return 0;
}