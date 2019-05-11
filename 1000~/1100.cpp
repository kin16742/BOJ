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
	char c;
	int cnt = 0;
	for (int i = 0; i<8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c;
			if (c == 'F' && (i + j) % 2 == 0) {
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}