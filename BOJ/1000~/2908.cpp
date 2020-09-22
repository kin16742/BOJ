#include <iostream>
using namespace std;
int main() {
	int a, b;
	int arr1[3], arr2[3];
	cin >> a >> b;
	for (int i = 0; i < 3; i++) {
		arr1[i] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < 3; i++) {
		arr2[i] = b % 10;
		b /= 10;
	}
	if (arr1[0] * 100 + arr1[1] * 10 + arr1[2] > arr2[0] * 100 + arr2[1] * 10 + arr2[2]) {
		for (int i = 0; i < 3; i++) {
			cout << arr1[i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			cout << arr2[i];
		}
	}
	cout << endl;
	return 0;
}