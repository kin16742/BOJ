#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, a, b;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	vector<pair<int, int>> v(t);
	for (int i = 0; i < t; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < t; i++) cout << v[i].second << ' ' << v[i].first << '\n';
}