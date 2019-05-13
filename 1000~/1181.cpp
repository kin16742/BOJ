#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n;
string a[20001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[n] = "ddddddddddddddddddddddddddddddddddddddd";
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j].size() < a[i].size()) swap(a[i], a[j]);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int cnt = 1;
		while (a[i].size() == a[i + 1].size()) {
			cnt++;
			i++;
		}
		sort(a + i - cnt + 1, a + i + 1);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != a[i + 1]) cout << a[i] << '\n';
	}
	return 0;

}