#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int a[3];
char c;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 3; i++) cin >> a[i];
	sort(a, a + 3);
	for (int i = 0; i < 3; i++) {
		cin >> c;
		cout << a[c - 'A'] << ' ';
	}
}