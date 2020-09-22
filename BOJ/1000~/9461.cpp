#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, t;
long long p[105];
int main() {
	cin >> t;
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	p[4] = 2;
	p[5] = 2;
	for (int i = 6; i <= 100; i++) {
		p[i] = p[i - 1] + p[i - 5];
	}
	while (t--) {
		cin >> n;
		cout << p[n] << endl;
	}
}