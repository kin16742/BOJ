#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n;
ll res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp = i;
		for (int j = 0; j < i + 1; j++) {
			res += temp++;
		}
	}
	cout << res << '\n';
	return 0;
}