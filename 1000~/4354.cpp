#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char T[1000010], P[1000010];
int if_fail[1000001];
int l, sl;

void get_fail(char* T) {
	int Tl = strlen(T);
	for (int i = 1, j = 0; i < Tl; ++i) {
		while (j > 0 && T[i] != T[j])
			j = if_fail[j - 1];

		if (T[i] == T[j])
			if_fail[i] = ++j;
	}
}


/*void Count(char *S, char *T) {
	get_fail(T);

	int Sl = strlen(S), Tl = strlen(T);
	for (int i = 0, j = 0; i < Sl; ++i) {
		while (j > 0 && S[i] != T[j])
			j = if_fail[j - 1];

		if (S[i] == T[j]) {
			if (j == (Tl - 1)) {
				res[cnt++] = i - Tl + 2;
				j = if_fail[j];
			}
			else
				j++;
		}
	}
}*/

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (1) {
		memset(T, 0, sizeof(T));
		memset(if_fail, 0, sizeof(if_fail));

		cin >> T;
		
		if (T[0] == '.' && T[1] == 0) break;

		get_fail(T);

		l = strlen(T);

		for (int i = l; i >= 0; i--) {
			if (i == 0) {
				cout << 1 << '\n';
				break;
			}
			if (if_fail[l - 1] == (double)((double)(i - 1) / i)*(double)(l)) {
				cout << i << '\n';
				break;
			}
		}
		
	}
	return 0;
}

