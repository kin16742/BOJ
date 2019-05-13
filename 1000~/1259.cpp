#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a, b;
char in[10];


bool isPalindrome(char *s) {
	int len = strlen(s);

	for (int idx = 0; idx < len / 2; ++idx) {
		if (s[idx] != s[len - idx - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> in) {
		if (in[0] == '0') break;
		printf("%s\n", isPalindrome(in) ? "yes" : "no");
	}

	return 0;
}


