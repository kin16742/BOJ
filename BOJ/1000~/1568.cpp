#include <iostream>
using namespace std;

int n, cnt, curr;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n != 0) {
		curr = 1;
		while (n >= curr) {
			n -= curr++;
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
