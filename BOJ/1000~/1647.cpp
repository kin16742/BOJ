#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, res;
int parent[100005];
priority_queue<pair<int, pair<int, int>>> pq1;
priority_queue<int> pq2;

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
		pq2.push(z);
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq1.push({ -c,{a,b} });
	}

	while (!pq1.empty()) {
		pair<int,pair<int,int>> temp = pq1.top();
		Union(temp.second.first, temp.second.second, -temp.first);
		pq1.pop();
	}

	cout << res - pq2.top() << '\n';
}