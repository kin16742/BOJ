#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int t, a;
int p[10005];
vector<int> prime;

int main() {
	cin >> t;
	p[0] = 1;
	p[1] = 1;
	for (int i = 2; i <= sqrt(10000); i++) {
		if (p[i] == 0) {
			for (int j = i + i; j <= 10000; j += i)
				p[j] = 1;
		}
	}
	for (int i = 2; i <= 10000; i++) {
		if (p[i] == 0) prime.push_back(i);
	}

	while (t--) {
		cin >> a;
		vector<pair<int, pair<int, int>>> v;
		for (int i = 0; i < prime.size(); i++) {
			if (prime[i] > a) break;
			for (int j = i; j < prime.size(); j++) {
				if (prime[j] > a) break;
				if (prime[i] + prime[j] == a)
					v.push_back({ abs(prime[i] - prime[j]),{ prime[i], prime[j] } });
			}
		}
		sort(v.begin(), v.end());
		cout << v[0].second.first << ' ' << v[0].second.second << endl;
	}
}