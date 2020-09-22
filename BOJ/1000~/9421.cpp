#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, p[1000001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	p[1] = 1;
	int range = sqrt(n);
	for (int i = 2; i <= range; i++) {
		if (p[i] == 1) continue;
		for (int j = i + i; j <= n; j += i) {
			p[j] = 1;
		}
	}
	for (int i = 7; i <= n; i++) {
		if (p[i] == 0) {
			int m = i;
			while (1) {
				int temp = 0;
				while (m != 0) {
					temp += pow(m % 10, 2);
					m /= 10;
				}
				if (temp == 1) {
					break;
				}
				if (temp < 7) {
					m = -1;
					break;
				}
				m = temp;
			}
			if (m != -1) cout << i << '\n';
		}
	}
	return 0;
}