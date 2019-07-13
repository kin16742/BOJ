#include <iostream>
#include <cmath>
using namespace std;
int p[300000];
int main() {
	p[0] = 1;
	p[1] = 1;
	for (int i = 2; i <= sqrt(300000); i++) {
		if (p[i] == 0) {
			for (int j = i + i; j <= 300000; j += i)
				p[j] = 1;
		}
	}
	int a;
	while (1) {
		cin >> a;
		if (a == 0) break;
		int cnt = 0;
		for (int i = a + 1; i <= 2*a; i++) {
			if (p[i] == 0) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}