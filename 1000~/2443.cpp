#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll a, b;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a;

	for (int i = a; i > 0; i--) {
		for (int j = 0; j < a - i; j++) cout << ' ';
		for (int j = 0; j < i * 2 - 1; j++) cout << '*';
		cout << endl;
	}

	return 0;

}