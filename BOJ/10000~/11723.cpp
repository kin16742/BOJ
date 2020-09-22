#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s = 0;
	int m , n;
	char a[10];
	cin >> m;
	while (m--) {
		cin >> a;
		if (a[1] == 'd') {
			cin >> n;
			s |= (1 << n);
		}
		else if (a[1] == 'e') {
			cin >> n;
			s &= ~(1 << n);
		}
		else if (a[1] == 'h') {
			cin >> n;
			if ((s & (1 << n)) == 0)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (a[1] == 'o') {
			cin >> n;
			s ^= (1 << n);
		}
		else if (a[1] == 'l') {
			s = (1 << 21) - 1;
		}
		else if (a[1] == 'm') {
			s = 0;
		}
	}
	return 0;
}