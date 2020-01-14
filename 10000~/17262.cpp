#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main(void) {
	int v, mA = 100010, mB = -1;
	cin >> v;
	while (v--) {
		int a, b;
		cin >> a >> b;
		mA = min(mA, b);
		mB = max(mB, a);
	}
	if (mA - mB > 0) cout << 0 << '\n';
	else cout << mB - mA << '\n';
}