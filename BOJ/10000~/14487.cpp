#include <iostream>
#include <algorithm>
using namespace std;

int n, v, maxV, totV;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	maxV = 0;
	totV = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		totV += v;
		maxV = max(maxV, v);
	}
	cout << totV - maxV << '\n';
	return 0;
}
