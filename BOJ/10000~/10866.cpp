#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n , d;
char a[15];
vector<int> v;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a;
		if (a[0] == 'e') {
			if (v.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if (a[0] == 'f') {
			if (!v.empty()) cout << v[0] << '\n';
			else cout << -1 << '\n';
		}
		if (a[0] == 'b') {
			if (!v.empty()) cout << v[v.size() - 1] << '\n';
			else cout << -1 << '\n';
		}
		if (a[0] == 's') {
			cout << v.size() << '\n';
		}
		if (a[1] == 'u' && a[5] == 'f') {
			cin >> d;
			v.insert(v.begin(), d);
		}
		if (a[1] == 'u' && a[5] == 'b') {
			cin >> d;
			v.push_back(d);
		}
		if (a[1] == 'o' && a[4] == 'f') {
			if (v.empty()) cout << -1 << '\n';
			else {
				cout << v[0] << '\n';
				v.erase(v.begin());
			}
		}
		if (a[1] == 'o' && a[4] == 'b') {
			if (v.empty()) cout << -1 << '\n';
			else {
				cout << v[v.size() - 1] << '\n';
				v.pop_back();
			}
		}

	}

	return 0;
}

