#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, A[30], d;
char c[101];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		int B = 0;
		for (int j = 0; j < strlen(c); j++) {
			A[i] |= (1 << c[j] - 'a');
		}
	}
	for (int i = 1; i < (1 << n); i++) {
		int res = 0, temp = i, cnt = 0;
		while (temp != 0) {
			if (temp & 1) res |= A[cnt];
			if (res == pow(2, 26) - 1) break;
			temp >>= 1;
			cnt++;
		}
		if (res == pow(2, 26) - 1) {
			d++;
		}
	}
	cout << d << '\n';
	return 0;
}