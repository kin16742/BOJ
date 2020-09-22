#include <iostream>
#include <string.h>
using namespace std;
char c[100];
int main() {
	cin >> c;
	for (int i = 0; i<strlen(c); i++) {
		if (c[i] >= 'A' && c[i] <= 'Z') cout << c[i];
	}
	cout << endl;
}