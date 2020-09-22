#include <iostream>
using namespace std;

int n;
char c[4];

int main() {
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> c;
		cout << c[0] + c[2] - '0' - '0' << '\n';
	}
	return 0;
}