#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char c[11];
bool chk;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c;
	for (int i = 1; i < strlen(c); i++) {
		ll num1 = 1, num2 = 1;
		for (int j = 0; j < i; j++) {
			num1 *= c[j] - '0';
		}
		for (int j = i; j < strlen(c); j++) {
			num2 *= c[j] - '0';
		}
		if (num1 == num2) {
			chk = 1;
			break;
		}
	}
	if (chk) cout << "YES" << '\n';
	else cout << "NO" << '\n';
	return 0;
}