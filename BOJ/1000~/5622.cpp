#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int arr[10] = { 2,3,4,5,6,7,8,9,10,11 };
	char d[15];
	int result = 0;
	cin >> d;
	for (int i = 0; i < strlen(d); i++) {
		if (d[i] >= 'A'&&d[i] <= 'C')
			result += arr[1];
		if (d[i] >= 'D'&&d[i] <= 'F')
			result += arr[2];
		if (d[i] >= 'G'&&d[i] <= 'I')
			result += arr[3];
		if (d[i] >= 'J'&&d[i] <= 'L')
			result += arr[4];
		if (d[i] >= 'M'&&d[i] <= 'O')
			result += arr[5];
		if (d[i] >= 'P'&&d[i] <= 'S')
			result += arr[6];
		if (d[i] >= 'T'&&d[i] <= 'V')
			result += arr[7];
		if (d[i] >= 'W'&&d[i] <= 'Z')
			result += arr[8];
	}
	cout << result << endl;
	return 0;
}