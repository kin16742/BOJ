#include <iostream>
#include <algorithm>
using namespace std;

int t, a, b, arr[3] = { 1,0,0 };

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		swap(arr[a - 1], arr[b - 1]);
	}
	for (int i = 0; i<3; i++) {
		if (arr[i]) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}