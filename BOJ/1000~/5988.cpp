#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char a[65];
int t;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> a;
		if (a[strlen(a) - 1] % 2 == 1) cout << "odd\n";
		else cout << "even\n";
	}


	return 0;

}