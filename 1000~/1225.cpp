#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char a[10001], b[10001];
ll res = 0, num = 0;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b;

	for (int i = 0; i < strlen(a); i++) {
		num += a[i] - '0';
	}

	for (int j = 0; j < strlen(b); j++) {
		res += num * (b[j] - '0');
	}
	cout << res << '\n';

	return 0;
}