#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, p[1001], num, cnt;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	int range = sqrt(1000);
	p[0] = 1;
	p[1] = 1;
	for (int i = 2; i <= range; i++) {
		if (p[i] == 0) {
			for (int j = i + i; j < 1001; j += i) {
				p[j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (p[num] == 0) cnt++;
	}
	cout << cnt << '\n';

	return 0;
}