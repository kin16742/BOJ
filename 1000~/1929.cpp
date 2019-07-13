#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, res;
int p[1000005];
int main() {
	cin >> n >> m;
	p[1] = 1;
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (!p[i]) {
			for (int j = i + i; j <= 1000000; j += i)
				p[j] = 1;
		}
	}
	for (int i = n; i <= m; i++) {
		if (!p[i]) printf("%d\n", i);
	}
}