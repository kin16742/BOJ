#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, k, a=0, b=0;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k) b++;
		else a++;
	}
	if (a > b) cout << "Junhee is not cute!\n";
	else cout << "Junhee is cute!\n";
	return 0;
}

