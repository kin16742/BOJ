#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int num, n, dd,  b[10], res = 100000000;
int main() {
	cin >> num >> n;
	for (int i = 0; i < n; i++) {
		cin >> dd;
		b[dd] = 1;
	}
	for (int i = 0; i <= 1000000; i++) {
		int temp = i, cnt = 0;
		while (temp > 0) {
			if (b[temp % 10] == 1) {
				cnt = -1;
				break;
			}
			cnt++;
			temp /= 10;
		}
		if (i == 0 && b[0] == 0)	cnt = 1;
		if (cnt > 0) {
			res = min(res, cnt + abs(i - num));
		}
	}
	res = min(res, abs(num - 100));
	cout << res << endl;
}