#include <iostream>
#include <algorithm>
using namespace std;

char a[5][20];

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 5; j++) {
			if(a[j][i] != '\0' && a[j][i] != '\n') cout << a[j][i];
		}
	}
	cout << '\n';
	return 0;
}