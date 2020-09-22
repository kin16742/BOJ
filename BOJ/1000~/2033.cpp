#include <iostream>
using namespace std;
int t, a = 10;

int main() {
	cin >> t;
	while (t > a) {
		if (t % a >= a / 2) t = (t / a + 1) * a;
		else t = (t / a) * a;
		a *= 10;
	}
	cout << t << endl;
}