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
	int n;
	for (int j = 0; j < 3; j++) {
		int z = 0;
		for (int i = 0; i < 4; i++) {
			cin >> n;
			if (n == 0) z++;
		}
		if (z == 0) cout << 'E' << '\n';
		else if (z == 1) cout << 'A'<< '\n';
		else if (z == 2) cout << 'B' << '\n';
		else if (z == 3) cout << 'C' << '\n';
		else cout << 'D' << '\n';
	}
	return 0;
}