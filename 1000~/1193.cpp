#include <iostream>
using namespace std;

int main() {
	int n;
	int c = 1, d = 1;
	cin >> n;
	while (n > d) {
		d += ++c;
	}
	n = n - (c - 1) * c / 2;
	if (c % 2 == 1) {
		cout << c - n + 1 << "/" << n << endl;
	}
	else {
		cout << n << "/" << c - n + 1 << endl;
	}
}