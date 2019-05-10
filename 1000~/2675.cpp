#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int t, n;
	char a[21];
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> a;
		for (int i = 0; i < strlen(a); i++) {
			for (int j = 0; j < n; j++)
				cout << a[i];
		}
		cout << endl;
	}
	return 0;
}