#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char c[505];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		memset(c, 0, sizeof(c));
		cin.getline(c, 500, '\n');
		if (c[0] == 'E' && c[1] == 'N' && c[2] == 'D' && c[3] == 0) break;
		for (int i = 0; i < strlen(c); i++) cout << c[strlen(c) - i - 1];
		cout << '\n';
	}
	
	return 0;
}