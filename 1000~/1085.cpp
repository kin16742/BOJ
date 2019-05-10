#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int x, y, w, h;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y >> w >> h;
	int minX = min(x, w - x);
	int minY = min(y, h - y);
	int res = min(minX, minY);
	cout << res << '\n';
	return 0;
}