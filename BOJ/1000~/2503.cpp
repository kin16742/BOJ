
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int t, a[1000], b, c, d, res = 0;

int main() {
	cin >> t;

	for (int i = 123; i < 988; i++) {
		if (i / 100 != (i % 100) / 10 && i / 100 != i % 10 && i % 10 != (i % 100) / 10) {
			a[i] = 1;
		}
		if (i / 100 == 0 || i % 100 / 10 == 0 || i % 10 == 0) a[i] = 0;
	}

	while (t--) {
		cin >> b >> c >> d;

		for (int i = 123; i < 988; i++) {
			int st = 0;
			int ba = 0;
			string one = to_string(b);
			string two = to_string(i);

			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					if (x == y && one[x] == two[y])
						st++;

					if (x != y && one[x] == two[y])
						ba++;
				}
			}
			if (st != c || ba != d)
				a[i] = 0;
		}
	}
	for (int i = 123; i <= 988; i++){
		if (a[i])
			res++;

	}

	cout << res << endl;

	return 0;
}