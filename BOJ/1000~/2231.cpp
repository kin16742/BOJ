#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int t;
bool chk = 0;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		int temp = i, sum = i;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == t) {
			cout << i << '\n';
			chk = 1;
			break;
		}
	}
	if (!chk) cout << 0 << '\n';
	return 0;

}