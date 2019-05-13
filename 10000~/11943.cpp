#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll a, b, aa, bb;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> aa >> bb;
	cout << min(a + bb, b + aa) << '\n';
	return 0;

}