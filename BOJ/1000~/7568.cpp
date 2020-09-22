#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[55], b[55], c[55];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		c[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (a[i] < a[j] && b[i] < b[j]) {
					c[i]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) cout << c[i] << ' ';
}