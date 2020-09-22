#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, result, a;
vector<int> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	do {
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			temp += abs(v[i] - v[i + 1]);
		}
		result = max(result, temp);
	} while (next_permutation(v.begin(), v.end()));
	cout << result << endl;
}
