#include <iostream>
using namespace std;
int t;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			if (j % 2 == 0) cout << '*';
			else cout << ' ';
		}
		cout << '\n';
		if (t != 1) {
			for (int j = 0; j < t; j++) {
				if (j % 2 == 1) cout << '*';
				else cout << ' ';
			}
			cout << '\n';
		}
	}
}