#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
char c[100];

int main(void) {
	cin >> n;
	cin >> c;
	n--;
	while (n--) {
		char ch;
		for (int i = 0; i < strlen(c); i++) {
			cin >> ch;
			if (ch != c[i]) c[i] = '?';
		}
	}
	cout << c << '\n';
}