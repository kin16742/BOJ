#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (b >= 45) {
		cout << a << ' ' << b - 45 << endl;
	}
	else {
		cout << (a + 23)%24 << ' ' << (b + 15) << endl;

	}
}