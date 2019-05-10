#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int cnt = 0;
		cin >> n;
		while (n != 0) {
			if (n % 2 == 1) cout << cnt << " ";
			n >>= 1;
			cnt++;
		}
		cout << endl;
	}
	return 0;
}
