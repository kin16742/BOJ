#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long s, cnt;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	long long n = 0, t = 0;
	while (s != 0 && s >= n) {
		n += t++ + 1;
		cnt++;
	}
	if (cnt == 0) cout << 0 << '\n';
	else	cout << cnt - 1 << '\n';
	return 0;
}
