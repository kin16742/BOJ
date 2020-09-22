#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int A[1200000];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s;

	while (scanf("%d", &s) != EOF) {
		int idx = s / 30;
		int val = s % 30;
		if (!(A[idx] & (1 << val))) {
			A[idx] |= (1 << val);
			cout << s << ' ';
		}
	}
	cout << '\n';
	return 0;
}