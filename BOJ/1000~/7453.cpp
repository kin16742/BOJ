#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, a[4001], b[4001], c[4001], d[4001];
ll res;
vector<int> ab, cd;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());
	for (int i = 0; i < ab.size(); i++) {
		int temp = (-1) * ab[i];
		res += (int)(upper_bound(cd.begin(), cd.end(), temp) - lower_bound(cd.begin(), cd.end(), temp));
	}
	cout << res << '\n';
	return 0;
}