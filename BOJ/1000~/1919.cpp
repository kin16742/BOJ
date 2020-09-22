#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

char a[1001], b[1001];
int ar[26], br[26], res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	for (int i = 0; i < strlen(a); i++) {
		ar[a[i] - 'a']++;
	}
	for (int i = 0; i < strlen(b); i++) {
		br[b[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (ar[i] != br[i]) res += max(ar[i], br[i]) - min(ar[i], br[i]);
	}
	cout << res << '\n';
	return 0;
}