#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n == -1) break;
		
		ll a[100001] = { 0, }, res = 0;

		for (int i = 1; i < n; i++) {
			if (n%i == 0) {
				a[i] = 1;
				res += i;
			}
		}
		if (res != n) printf("%d is NOT perfect.\n", n);
		else {
			printf("%d = 1", n);
			for (int i = 2; i < n; i++) {
				if (a[i] == 1) printf(" + %d", i);
			}
			printf("\n");
		}
	}
	return 0;
}