#include <iostream>
#include <algorithm>
using namespace std;

int t, r;

int main() {
	cin >> t;

	while (t--) {
		cin >> r;

		for (int i = 0; i < r; i++) {
			if (i == 0 || i == r - 1) {
				for (int j = 0; j < r; j++) {
					cout << '#';
				}
			}
			else {
				cout << '#';
				for (int j = 1; j < r - 1; j++) {
					cout << 'J';
				}
				cout << '#';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}