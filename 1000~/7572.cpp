#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, a, b;
	cin >> N;
	N += (2400 - 2013);
	a = (N + 5) % 12;
	b = (N + 9) % 10;
	printf("%c%c\n", a + 'A', b + '0');

	return 0;

}