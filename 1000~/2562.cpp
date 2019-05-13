#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll a, cnt = 1;
vector<pair<int, int>> v;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> a) {
		v.push_back({ a,cnt++ });
	}
	sort(v.begin(), v.end());
	cout << v.back().first << '\n' << v.back().second << '\n';
	return 0;

}