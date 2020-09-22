#include <iostream>
#include <algorithm>
using namespace std;

bool t[101][101];
int a, b, c, d, res = 0;

int main() {
	for(int k=0;k<4;k++) {
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				t[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (t[i][j] == 1) res++;
		}
	}
	cout << res << '\n';
	return 0;
}