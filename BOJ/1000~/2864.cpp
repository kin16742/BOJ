#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

char a[10], b[10];
int mi1, ma1, mi2, ma2;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	for (int i = 0; i < strlen(a); i++) {
		mi1 *= 10;
		ma1 *= 10;

		if (a[i] - '0' == 6 || a[i] - '0' == 5) {
			mi1 += 5;
			ma1 += 6;
		}
		else {
			mi1 += a[i] - '0';
			ma1 += a[i] - '0';
		}
	}
	for (int i = 0; i < strlen(b); i++) {
		mi2 *= 10;
		ma2 *= 10;

		if (b[i] - '0' == 6 || b[i] - '0' == 5) {
			mi2 += 5;
			ma2 += 6;
		}
		else {
			mi2 += b[i] - '0';
			ma2 += b[i] - '0';
		}
	}
	cout << mi1 + mi2 << ' ' << ma1 + ma2 << '\n';
	return 0;
}