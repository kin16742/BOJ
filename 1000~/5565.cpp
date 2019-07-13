#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int a, b, res;
	cin >> b;
	for (int i = 0; i < 9; i++) {
		cin >> a;
		b -= a;
	}
	cout << b << endl;
	return 0;
}