#include <iostream>
#include <algorithm>
using namespace std;

bool a[105][105];
int q, w, e, res = 0;

int main() {
	cin >> q;

	while (q--) {
		cin >> w >> e;
		for (int i = w; i < w + 10; i++) {
			for (int j = e; j < e + 10; j++) {
				a[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (a[i][j] == 1) res++;
		}
	}
	cout << res << '\n';
	return 0;
}