#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll a, b, c;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	int cnt = a / (c - b) + 1;
	if (c - b <= 0) cnt = -1;
	cout << cnt << '\n';
	return 0;
}