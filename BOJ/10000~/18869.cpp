#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, ans;
vector<vector<int>> res;

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		vector<int> temp(n), v;

		for (int j = 0; j < n; j++) 
			cin >> temp[j];
		v = temp;

		sort(v.begin(), v.end());

		v.resize(unique(v.begin(), v.end()) - v.begin());
		for (int j = 0; j < n; j++) 
			temp[j] = lower_bound(v.begin(), v.end(), temp[j]) - v.begin();
		
		res.push_back(temp);
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < res.size();) {
		int idx = i;
		while (idx < res.size() && res[i] == res[idx])
			idx++;
		ans += (idx - i) * (idx - i - 1) / 2;
		i = idx;
	}
	cout << ans << '\n';
}