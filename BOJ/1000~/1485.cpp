#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
#include <cmath>
using namespace std;

int t;
int dotX[4];
int dotY[4];
set<int> s;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(dotX, 0, sizeof(dotX));
		memset(dotY, 0, sizeof(dotY));
		for (int i = 0; i < 4; i++) {
			cin >> dotX[i] >> dotY[i];
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i != j) {
					s.insert(pow(dotX[i] - dotX[j], 2) + pow(dotY[i] - dotY[j], 2));
				}
			}
		}
		if (s.size() > 2) cout << 0 << endl;
		else cout << 1 << endl;
		s.clear();
	}
	return 0;
}
