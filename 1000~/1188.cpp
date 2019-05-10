#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int S, P, ss[101], cur, cnt;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> S >> P;
	cur = S * P;
	for (int i = 0; i < S; i++) {
		ss[i] = P;
	}
	while (cur != 0) {
		for (int i = 0; i < S; i++) {
			if (ss[i] > S) {
				ss[i] -= S;
				cur -= S;
				cnt++;
			}
			if (ss[i] == S) {
				ss[i] -= S;
				cur -= S;
			}
			if (ss[i] < S) {
				ss[i + 1] += ss[i];
				ss[i] = 0;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}