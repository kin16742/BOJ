#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, k;
bool visit[100001];

struct dis {
	int x;
	int s;
};

int BFS(int _n, int _k) {
	visit[n] = true;
	queue<dis> q;
	q.push({ n,0 });
	while (!q.empty()) {
		int now = q.front().x;
		int step = q.front().s;
		q.pop();

		if (now == _k) return step;

		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 0) next = now + 1;
			else if (i == 1) next = now - 1;
			else if (i == 2) next = now * 2;

			if (next >= 0 && next <= 100000) {
				if (visit[next] == false) {
					visit[next] = true;
					q.push({ next, step + 1 });
				}
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	
	int ans = BFS(n, k);
	cout << ans << '\n';
	return 0;
}
