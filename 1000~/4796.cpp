#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int l, p, v, cnt = 1;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		int res = 0;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;
		while (v > 0) {
			if (v >= p) {
				v -= p;
				res += l;
			}
			else {
				if (v >= l) {
					res += l;
				}
				else {
					res += v;
				}
				v = 0;
			}
		}
		printf("Case %d: %d\n", cnt++, res);
	}
	return 0;
}