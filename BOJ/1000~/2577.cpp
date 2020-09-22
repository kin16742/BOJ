#include <iostream>
using namespace std;
int main() {
	int a, b, c, result, i = 0;
	int arr[10] = { 0 };
	cin >> a >> b >> c;
	result = a * b * c;
	while (result != 0) {
		arr[result % 10]++;
		result /= 10;
		i++;
	}
	for (int j = 0; j < 10; j++) {
		cout << arr[j] << endl;
	}
	return 0;
}