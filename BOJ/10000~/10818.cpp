#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, a, ma = -1000000, mi = 1000000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ma = max(ma, a);
		mi = min(mi, a);
	}
	cout << mi << ' ' << ma << endl;
}