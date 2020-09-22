#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool visit[1000001];
struct point {
	int floor;
	int step;
};
int BFS(int s) {
	visit[s] = true;
	queue<point> q;
	q.push({s, 0});

	while (!q.empty()) {
		int now = q.front().floor;
		int step = q.front().step;
		q.pop();

		if (now == G) return step;

		for (int i = 0; i < 2; i++) {
			int next;
			if (i == 0) next = now + U;
			else next = now - D;

			if (next >= 0 && next <= F + U * D) {
				if (visit[next] == false) {
					visit[next] = true;
					q.push({ next,step + 1 });
				}
			}
		}
	}
	return -1;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> F >> S >> G >> U >> D;
	int ans = BFS(S);
	if (ans == -1) cout << "use the stairs\n";
	else cout << ans << '\n';
	return 0;
}
