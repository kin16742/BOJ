#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

double a, b, c, d;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c >> d;
	double ans[4];
	ans[0] = a / c + b / d;
	ans[1] = c / d + a / b;
	ans[2] = d / b + c / a;
	ans[3] = b / a + d / c;
	double res = 0, idx = 0;
	for (int i = 0; i < 4; i++) {
		if (res < ans[i]) {
			idx = i;
			res = ans[i];
		}
	}
	cout << idx << '\n';
	return 0;
}