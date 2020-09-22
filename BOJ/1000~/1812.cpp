#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a[1000], sum;	

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= 2;
	for (int i = 0; i < n; i++) {
		int now = sum;
		for (int j = 0; j < n / 2; j++) {
			now -= a[(i + 1 + 2 * j) % n];
		}
		cout << now << '\n';
	}
}