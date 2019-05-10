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
	a /= 100;
	a *= 100;
	while (a % b != 0) a++;
	cout << (a / 10) % 10 << a % 10 << '\n';
	return 0;
}