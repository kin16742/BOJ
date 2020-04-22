#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, res;
int parent[1005];
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int x, int y, int z) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
		res += z;
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= 1000; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ -c,{a,b} });
	}

	while (!pq.empty()) {
		pair<int,pair<int,int>> temp = pq.top();
		Union(temp.second.first, temp.second.second, -temp.first);
		pq.pop();
	}

	cout << res << '\n';
}