#include <iostream>
#include <algorithm>
using namespace std;

int a, b, t[105], res = 0;

int main() {
	cin >> a >> b;
	for (int i = 0; i < a; i++) cin >> t[i];

	for (int i = 0; i < a; i++) {
		for (int j = i + 1; j < a; j++) {
			for (int k = j + 1; k < a; k++) {
				if (t[i] + t[j] + t[k] <= b) res = max(res, t[i] + t[j] + t[k]);
			}
		}
	}

	cout << res << '\n';

	return 0;
}