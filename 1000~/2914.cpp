#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	cout << a * (b - 1) + 1 << '\n';
	return 0;
}