#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int a[3], b[2], res = 40000;
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			res = min(res, a[i] + b[j] - 50);
		}
	}
	cout << res << endl;
	return 0;
}