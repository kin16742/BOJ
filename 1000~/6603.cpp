#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int k, s[13];
vector<vector<int>> A;
bool visit[13];

void DFS(int _i, int _l) {
	visit[_i] = 1;

	if (_l == 6) {
		for (int i = 0; i < k; i++) {
			if (visit[i] == 1) cout << s[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < A[_i].size(); i++) {
			if (!visit[A[_i][i]]) {
				DFS(A[_i][i], _l + 1);
				visit[A[_i][i]] = 0;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> k;
		if (k == 0) break;
		
		A.resize(k + 1);

		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				A[i].push_back(j);
			}
		}
		for (int i = 0; i <= k - 6; i++) {
			memset(visit, 0, sizeof(visit));
			DFS(i, 1);
		}
		cout << '\n';
		A.clear();
	}
	return 0;
}