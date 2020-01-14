#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		int cnt = 0;
		char c[10];
		cin >> c;
		for (int i = 0; i < 4; i++) c[i] -= '0';
		while (1) {
			int temp = c[0] * 1000 + c[1] * 100 + c[2] * 10 + c[3];
			if (temp == 6174) break;
			sort(c, c + 4);
			int temp1 = c[3] * 1000 + c[2] * 100 + c[1] * 10 + c[0];
			int temp2 = c[0] * 1000 + c[1] * 100 + c[2] * 10 + c[3];
			cnt++;
			c[0] = (temp1 - temp2) / 1000;
			c[1] = (temp1 - temp2) / 100 % 10;
			c[2] = (temp1 - temp2) / 10 % 10;
			c[3] = (temp1 - temp2) % 10;
		}
		cout << cnt << '\n';
	}
}