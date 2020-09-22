#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, l;
pair<int, int> dd[100005];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> dd[i].first >> dd[i].second;
	}
	sort(dd, dd + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while (dd[i].first < dd[i].second) {
			cnt++;
			dd[i].first += l;
		}
		if (dd[i].first > dd[i + 1].first) {
			dd[i + 1].first = dd[i].first;
		}
	}
	cout << cnt << '\n';

	return 0;
}