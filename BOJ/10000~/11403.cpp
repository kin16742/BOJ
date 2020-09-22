#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, cnt;
int arr[100][100];
vector<vector<int>> graph;
bool visit[100], DFSvisit[100];

void DFS(int s) {
	DFSvisit[s] = true;

	for (int i = 0; i < graph[s].size(); i++) {
		int next = graph[s][i];
		if (next == cnt) arr[cnt][next] = 1;
		if (DFSvisit[next] == false){

			arr[cnt][next] = 1;
			DFS(next);
		
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	memset(arr, 0, sizeof(graph));
	memset(visit, 1, sizeof(visit));

	graph.resize(n + 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				graph[i].push_back(j);
				visit[i] = visit[j] = false;
			}
		}
	}

	for (cnt = 0; cnt < n; cnt++) {
		memcpy(DFSvisit, visit, sizeof(visit));
		DFS(cnt);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
