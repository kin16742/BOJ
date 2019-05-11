#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char c[101];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c;
	bool b = 1;
	for (int i = 0; i < strlen(c) / 2; i++) {
		if (c[i] != c[strlen(c) - 1 - i]) {
			b = 0;
			break;
		}
	}
	if (b) cout << 1 << '\n';
	else cout << 0 << '\n';
	return 0;
}