#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a[1000000];
vector<int> v;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	v.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (a[i] > v[v.size() - 1]) v.push_back(a[i]);
		else {
			v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
		}
	}
	cout << v.size() << '\n';
	return 0;
}