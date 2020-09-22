#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

long long int m[1001][1001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int a, b;
	memset(m, -1, sizeof(m));
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		m[i][0] = m[i][i] = 1;
			for (int j = 1; j < i; j++) {
				m[i][j] = (m[i - 1][j] + m[i - 1][j - 1]) % 10007;
			}
	}
	cout << m[a][b] << '\n';
	return 0;
}