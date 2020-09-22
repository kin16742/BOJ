#include <iostream>
#include <algorithm>
using namespace std;

int t, d, r, cnt;
bool date[2000001];

int main() {
	cin >> t >> d;

	while (t--) {
		cin >> r;

		int temp = r;
		
		while (temp <= d) {
			date[temp] = 1;
			temp += r;
		}
	}

	for (int i = 1; i <= d; i++) {
		if (date[i]) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}