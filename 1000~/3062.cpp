#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char a[8], b[8];
int t;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int res = 0, cnt = 0;
		bool chk = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> a;
		for (int i = 0; i < strlen(a); i++) {
			res *= 10;
			res += (a[i] + a[strlen(a) - i - 1] - '0' * 2);
		}
		while (res > 0) {
			b[cnt++] = res % 10 + 1;
			res /= 10;
		}
		for (int i = 0; i < cnt / 2; i++) {
			if (b[i] != b[strlen(b) - i - 1]) chk = 1;
		}
		if (!chk) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	return 0;

}