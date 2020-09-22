#include <iostream>
#include <string.h>
using namespace std;
int main() {
	char arr[100];
	int a[26];
	for (int i = 0; i < 26; i++)
		a[i] = -1;
	cin >> arr;
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == 'a') {
			if(a[0]==-1) a[0] = i;
		}
		if (arr[i] == 'b') {
			if (a[1] == -1) a[1] = i;
		}
		if (arr[i] == 'c') {
			if (a[2] == -1) a[2] = i;
		}
		if (arr[i] == 'd') {
			if (a[3] == -1) a[3] = i;
		}
		if (arr[i] == 'e') {
			if (a[4] == -1) a[4] = i;
		}
		if (arr[i] == 'f') {
			if (a[5] == -1) a[5] = i;
		}
		if (arr[i] == 'g') {
			if (a[6] == -1) a[6] = i;
		}
		if (arr[i] == 'h') {
			if (a[7] == -1) a[7] = i;
		}
		if (arr[i] == 'i') {
			if (a[8] == -1) a[8] = i;
		}
		if (arr[i] == 'j') {
			if (a[9] == -1) a[9] = i;
		}
		if (arr[i] == 'k') {
			if (a[10] == -1) a[10] = i;
		}
		if (arr[i] == 'l') {
			if (a[11] == -1) a[11] = i;
		}
		if (arr[i] == 'm') {
			if (a[12] == -1) a[12] = i;
		}
		if (arr[i] == 'n') {
			if (a[13] == -1) a[13] = i;
		}
		if (arr[i] == 'o') {
			if (a[14] == -1) a[14] = i;
		}
		if (arr[i] == 'p') {
			if (a[15] == -1) a[15] = i;
		}
		if (arr[i] == 'q') {
			if (a[16] == -1) a[16] = i;
		}
		if (arr[i] == 'r') {
			if (a[17] == -1) a[17] = i;
		}
		if (arr[i] == 's') {
			if (a[18] == -1) a[18] = i;
		}
		if (arr[i] == 't') {
			if (a[19] == -1) a[19] = i;
		}
		if (arr[i] == 'u') {
			if (a[20] == -1) a[20] = i;
		}
		if (arr[i] == 'v') {
			if (a[21] == -1) a[21] = i;
		}
		if (arr[i] == 'w') {
			if (a[22] == -1) a[22] = i;
		}
		if (arr[i] == 'x') {
			if (a[23] == -1) a[23] = i;
		}
		if (arr[i] == 'y') {
			if (a[24] == -1) a[24] = i;
		}
		if (arr[i] == 'z') {
			if (a[25] == -1) a[25] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}