#include <iostream>
using namespace std;

int main() {
	int a, b, t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		long long int result = 1, go = 1, cnt = 1, way = b - a;
		while (way > result) {
			if (cnt % 2 == 1) {
				cnt++;
				result += go;
			}
			else {
				cnt++;
				result += ++go;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}