
#include <iostream>
#include <algorithm>
using namespace std;

int t, cnt = 0, res = 0;
int a[6] = { 500,100,50,10,5,1 };

int main() {
	cin >> t;
	
	t = 1000 - t;

	while (t) {
		if (t >= a[cnt]) {
			t -= a[cnt];
			res++;
		}
		else cnt++;
	}
	cout << res << '\n';

	return 0;
}