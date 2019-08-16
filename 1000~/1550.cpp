#include <iostream>
#include <string.h>
using namespace std;
char c[10];
int result;
int main() {
	cin >> c;
	for (int i = 0; i<strlen(c); i++) {	
		result *= 16;
		if (c[i] >= '0' && c[i] <= '9') result += c[i] - '0';
		else result += c[i] - 'A' + 10;
	}
	cout << result << endl;
}