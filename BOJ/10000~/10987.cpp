#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int cnt = 0;
char c[105];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == 'a') cnt++;
		if (c[i] == 'e') cnt++;
		if (c[i] == 'i') cnt++;
		if (c[i] == 'o') cnt++;
		if (c[i] == 'u') cnt++;
	}
	cout << cnt << '\n';
	return 0;
}

