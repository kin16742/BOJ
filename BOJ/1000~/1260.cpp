#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> DFSvisit;
vector<bool> BFSvisit;
int n, m, v, a, b;

void DFS(int s) {
	DFSvisit[s] = true;
	cout << s << ' ';
	
	for (int i = 0; i < graph[s].size(); i++) {
		int next = graph[s][i];
		if (DFSvisit[next] == false) DFS(next);
	}
}

void BFS(int s) {
	queue<int> q;
	q.push(s);
	BFSvisit[s] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		cout << here << ' ';
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			if (BFSvisit[next] == false) {
				BFSvisit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> v;

	graph.resize(n + 1);
	DFSvisit.resize(n + 1);
	BFSvisit.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i=1; i<=n; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(v);
	cout << '\n';
	BFS(v);
	cout << '\n';
	return 0;
}
