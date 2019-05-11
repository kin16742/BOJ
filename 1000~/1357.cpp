#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int a, b;
int rev(int s) {
	int ret = 0;
	while (s != 0) {
		ret *= 10;
		ret += s % 10;
		s /= 10;
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	cout << rev(rev(a) + rev(b)) << '\n';
	return 0;
}