#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, d;
int dd[10001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dd,0,sizeof(dd));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d;
		dd[d]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (dd[i] > 0) {
			for (int j = 0; j < dd[i]; j++) {
				cout << i << '\n';
			}
		}
	}
	return 0;
}
