#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, l;
char c[105];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) cout << '*';
		cout << '\n';
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) cout << '*';
		cout << '\n';
	}
	return 0;
}

