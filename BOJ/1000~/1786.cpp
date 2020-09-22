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
ll cnt = 0;
int res[1000001];

void get_fail(char* T) {
	int Tl = strlen(T);
	for (int i = 1, j = 0; i < Tl; ++i) {
		while (j > 0 && T[i] != T[j])
			j = if_fail[j - 1];

		if (T[i] == T[j])
			if_fail[i] = ++j;
	}
}


void Count(char *S, char *T) {
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
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(if_fail, 0, sizeof(if_fail));
	memset(res, 0, sizeof(res));

	cin.getline(T, 1000005);
	cin.getline(P, 1000005);

	Count(T, P);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) cout << res[i] << ' ';
	return 0;

}