#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, a[101][101], garo[101][101], sero[101][101], s, g;
char c;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == '.') a[i][j] = 1;
			if (c == 'X') a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		garo[i][0] = a[i][0];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i][j] != 0) garo[i][j] += garo[i][j - 1] + a[i][j];
			
		}
	}
	for (int i = 0; i < n; i++) {
		sero[0][i] = a[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0) sero[i][j] += sero[i - 1][j] + a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (garo[i][j] == 2) g++;
			if (sero[i][j] == 2) s++;
		}
	}
	cout << g << ' ' << s << '\n';
	return 0;
}