#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, num=665;
int main() {
	cin >> n;
	while (1) {
		num++;
		int temp = num, idx = 0;
		char aa[20];
		while (temp>0) {
			aa[idx++] = temp % 10;
			temp /= 10;
		}
		int cnt = 0;
		for (int i = 0; i < idx - 2; i++) {
			bool chk = 0;
			if (aa[i] == 6 && aa[i + 1] == 6 && aa[i + 2] == 6) {
				n--;
				break;
			}
		}
		if (n == 0) break;
	}
	cout << num << endl;
}