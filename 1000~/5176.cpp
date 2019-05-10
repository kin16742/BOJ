#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int k, p, m, tmp, cnt, seat[501];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	while (k--) {
		memset(seat, 0, sizeof(seat));
		cnt = 0;
		cin >> p >> m;
		for (int i = 0; i < p; i++) {
			cin >> tmp;
			seat[tmp]++;
		}
		for (int i = 1; i <= m; i++) {
			if(seat[i] != 0)
				cnt += seat[i] - 1;
		}
		cout << cnt << '\n';
	}
	return 0;
}
