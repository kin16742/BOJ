#include <iostream>
#include <algorithm>
using namespace std;

double d1, d2;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> d1;
	while (1) {
		cin >> d2;
		if (d2 == 999) break;
		printf("%.2f\n",d2-d1);
		d1 = d2;
	}
	return 0;
}
