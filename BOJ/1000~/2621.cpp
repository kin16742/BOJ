#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int nc[10];
int ac[4];
int p, t, f, num, res;
bool same, straight;
char c;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		cin >> c >> num;
		res = max(num, res);
		nc[num]++;
		if (c == 'R') ac[0]++;
		if (c == 'G') ac[1]++;
		if (c == 'B') ac[2]++;
		if (c == 'Y') ac[3]++;
	}
	for (int i = 1; i <= 9; i++) {
		if (nc[i] == 1) {
			bool st = 1;
			for (int j = i + 1; j < i + 5; j++) {
				if (nc[j] != 1) {
					st = 0;
					break;
				}
			}
			if (st) straight = true;
		}
		if (nc[i] == 2) p++;
		if (nc[i] == 3) t++;
		if (nc[i] == 4) f++;
	}
	for (int i = 0; i < 4; i++) {
		if (ac[i] == 5) same = true;
	}

	if (same) {
		if (straight) res += 900;
		else res += 600;
	}
	else {
		if (straight) res += 500;
		else if (f) {
			for (int i = 1; i <= 9; i++) 
				if (nc[i] == 4) res = i;
			
			res += 800;
		}
		else if (t) {
			if (p) {
				for (int i = 1; i <= 9; i++) 
					if (nc[i] == 3) res = i * 10;
				
				for (int i = 1; i <= 9; i++) 
					if (nc[i] == 2) res += i;
				
				res += 700;
			}
			else {
				for (int i = 1; i <= 9; i++) 
					if (nc[i] == 3) res = i;

				res += 400;
			}
		}
		else if (p) {
			if (p == 2) {
				for (int i = 1; i <= 9; i++) 
					if (nc[i] == 2) res = i * 10;
				
				for (int i = 1; i <= 9; i++) {
					if (nc[i] == 2) {
						res += i;
						break;
					}
				}
				res += 300;
			}
			else {
				for (int i = 1; i <= 9; i++) 
					if (nc[i] == 2) res = i;
				
				res += 200;
			}
		}
		else res += 100;
	}
	cout << res << '\n';
	return 0;
}