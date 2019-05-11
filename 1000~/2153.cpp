#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char c[21];
int p[1050];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int range = sqrt(1050);
	for (int i = 2; i <= range; i++) {
		if (p[i] != 1) {
			for (int j = i * i; j <= 1050; j += i) {
				p[j] = 1;
			}
		}
	}
	cin >> c;
	int num = 0;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] >= 'a' && c[i] <= 'z') num += c[i] - 'a' + 1;
		if (c[i] >= 'A' && c[i] <= 'Z') num += c[i] - 'A' + 27;
	}
	if (p[num] == 0) cout << "It is a prime word.\n";
	else cout << "It is not a prime word.\n";
	return 0;
}