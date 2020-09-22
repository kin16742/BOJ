#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r, a, b, cnt = 0;
	cin >> r >> a >> b;
	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}