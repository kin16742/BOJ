#include <iostream>
#include <string.h>
using namespace std;
char c[105];
int main() {
	cin >> c;
	for (int i = 0; i<strlen(c); i++) {
		if (c[i] >= 'a' && c[i] <= 'z') c[i] = c[i] - 'a' + 'A';
		else c[i] = c[i] - 'A' + 'a';
	}
	cout << c << endl;
}