#include <iostream>
using namespace std;

int main() {
	int n, i = 1, j = 1;
	cin >> n;
	while (n > i) {
		i += j * 6;
		j++;
	}
	cout << j << endl;
	return 0;
}