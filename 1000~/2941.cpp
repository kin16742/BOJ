#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int result = 0;
	char arr[101];
	int i = 0;
	cin >> arr;
	while (i != strlen(arr)) {
		switch (arr[i]) {
		case 'c':
			if (arr[i + 1] == '=') {
				result++;
				i++;
			}
			else if (arr[i + 1] == '-') {
				result++;
				i++;
			}
			else result++;
			break;
		case 'd':
			if (arr[i + 1] == 'z' && arr[i + 2] == '=') {
				result++;
				i += 2;
			}
			else if (arr[i + 1] == '-') {
				result++;
				i++;
			}
			else result++;
			break;
		case 'l':
			if (arr[i + 1] == 'j') {
				result++;
				i++;
			}
			else result++;
			break;
		case 'n':
			if (arr[i + 1] == 'j') {
				result++;
				i++;
			}
			else result++;
			break;
		case 's':
			if (arr[i + 1] == '=') {
				result++;
				i++;
			}
			else result++;
			break;
		case 'z':
			if (arr[i + 1] == '=') {
				result++;
				i++;
			}
			else result++;
			break;
		default:
			result++;
		}
		i++;
	}
	cout << result << endl;
	return 0;
}