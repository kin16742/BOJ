#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	for (int i = 2; i <= num; i++) {
		while (num%i == 0) {
			num /= i;
			cout << i << '\n';
		}
	}
	return 0;
}