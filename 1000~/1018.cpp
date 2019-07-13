#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cc[55][55];
char ch;
int a, b, res = 100;
int main() {
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> ch;
			if (ch == 'W') cc[i][j] = 0;
			if (ch == 'B') cc[i][j] = 1;
		}
	}
	for (int i = 0; i < a - 7; i++) {
		for (int j = 0; j < b - 7; j++) {
			int cnt = 0;

			for (int x = i; x < i + 8; x++) {
				for (int y = j; y < j + 8; y++) {
					if ((x - i) % 2 == 0) {
						if ((y - j) % 2 == 0) {
							if (cc[x][y] != 0) cnt++;
						}
						else {
							if (cc[x][y] != 1) cnt++;
						}
					}
					else {
						if ((y - j) % 2 == 0) {
							if (cc[x][y] != 1) cnt++;
						}
						else {
							if (cc[x][y] != 0) cnt++;
						}
					}
				}
			}
			res = min(res, cnt);
			cnt = 0;
			for (int x = i; x < i + 8; x++) {
				for (int y = j; y < j + 8; y++) {
					if ((x - i) % 2 == 0) {
						if ((y - j) % 2 == 0) {
							if (cc[x][y] != 1) cnt++;
						}
						else {
							if (cc[x][y] != 0) cnt++;
						}
					}
					else {
						if ((y - j) % 2 == 0) {
							if (cc[x][y] != 0) cnt++;
						}
						else {
							if (cc[x][y] != 1) cnt++;
						}
					}
				}
			}
			res = min(res, cnt);
		}
	}
	cout << res << endl;
}