#include <iostream>
#include <algorithm>
using namespace std;
int res, y, x, temp;
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> temp;
			if (temp > res) {
				res = temp;
				y = i;
				x = j;
			}
		}
	}
	cout << res << endl;
	cout << y << ' ' << x << endl;
}