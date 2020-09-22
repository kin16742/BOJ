#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, cnt = 0;
	cin >> x;
	while (x) {
		if (x & 1) cnt++;
		x = (x >> 1);
	}
	cout << cnt << '\n';
	return 0;
}
