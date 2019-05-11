#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char c[15];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c;
	sort(c, c + strlen(c));
	for (int i = strlen(c) - 1; i >= 0; i--) {
		cout << c[i];
	}
	cout << '\n';
}