
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a[1001];
		double d, cnt = 0, sum = 0;
		cin >> d;
		for (int i = 0; i < d; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sum /= d;
		for (int i = 0; i < d; i++) {
			if (a[i] > sum) cnt++;
		}
		printf("%.3lf%%\n", 100 * cnt / d);
	}
}