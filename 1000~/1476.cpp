#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int e, s, m, year = 1;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> e >> s >> m;
	while (1) {
		int a = year % 15;
		int b = year % 28;
		int c = year % 19;
		if (!a) a = 15;
		if (!b) b = 28;
		if (!c) c = 19;
		if (a == e && b == s && c == m) break;
		year++;
 	}
	cout << year << '\n';
	return 0;
}