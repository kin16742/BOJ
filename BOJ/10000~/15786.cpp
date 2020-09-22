#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m;
char a[1001], b[1001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> a;

	while (m--) {
		int curr = 0;

		cin >> b;

		for (int i = 0; i < strlen(b); i++) {
			if (a[curr] == b[i]) curr++;
		}

		if (curr == n) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}


