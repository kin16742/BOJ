#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int r, s;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> s;
	cout << 2 * s - r << '\n';
	return 0;
}