#include <iostream>
using namespace std;
int a[5], temp, idx;
int main() {
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<4; j++) {
			cin >> temp;
			a[i] += temp;
		}
	}
	for (int i = 1; i<5; i++) {
		if (a[idx] < a[i]) idx = i;
	}
	cout << idx + 1 << ' ' << a[idx] << endl;
}