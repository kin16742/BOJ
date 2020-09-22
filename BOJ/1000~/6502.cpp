#include <iostream>
#include <cmath>
using namespace std;

double r, w, l;
int cnt;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cnt = 1;
	while (1) {
		cin >> r;
		if (r == 0) break;
		cin >> w >> l;
		double si = sqrt(pow(w, 2) + pow(l, 2));
		if (si <= r * 2)
			printf("Pizza %d fits on the table.\n", cnt++);
		else
			printf("Pizza %d does not fit on the table.\n", cnt++);
	}
	return 0;
}
