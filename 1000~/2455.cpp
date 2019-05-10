#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, result = 0, people = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		people = people - a + b;
		result = max(result, people);
	}
	cout << result << '\n';
	return 0;
}
