#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int t, cnt = 0;
int main() {
	cin >> t;
	while (t / 10 > 0) {
		int temp = 1;
		while (t) {
			temp *= t % 10;
			t /= 10;
		}
		t = temp;
		cnt++;
	}
	cout << cnt << '\n';
}