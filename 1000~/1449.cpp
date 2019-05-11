#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, l, a[2001], res = 0, num;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> num;
		a[num]++;
	}

	for (int i = 1; i <= 1000; i++) {
		if (a[i] > 0) {
			for (int j = 0; j < l; j++) {
				a[i + j]--;
			}
			res++;
			i += l - 1;
		}
	}

	cout << res << '\n';

	return 0;
}