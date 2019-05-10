#include <iostream>
using namespace std;
char arr[1000000];
int main() {
	int max = 0;
	char result;
	int a[26] = { 0 };
	cin >> arr;
	for (int i = 0; i < 1000000; i++) {
		if (arr[i] < 'a')
			a[(int)(arr[i] - 65)]++;
		else
			a[(int)(arr[i] - 97)]++;
	}
	for (int i = 0; i < 26; i++) {
		if (a[i] > max) {
			max = a[i];
			result = (char)(i+65);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (a[i] == max && i != (int)(result)-65) max = -1;
	}
	if (max == -1) cout << "?" << endl;
	else cout << result << endl;
	return 0;
}