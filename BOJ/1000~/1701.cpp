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
int l;
int res;

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


	cin.getline(T, 5005);
	
	for (int i = 0; i < strlen(T); i++) {
		memset(if_fail, 0, sizeof(if_fail));
		get_fail(T + i);
		for (int f = 0; f < strlen(T + i); f++) {
			res = max(res, if_fail[f]);
		}
	}
	cout << res << '\n';
	
	return 0;

}