#include <iostream>
#include <vector>
using namespace std;
long long t;
vector<int> v;
int main() {
	cin >> t;
	while (t) {
		v.push_back(t % 2);
		t /= 2;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[v.size() - 1 - i];
	}
	cout << endl;
}