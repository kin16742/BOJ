#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
vector<pair<int, int>> v;
 void moveHanoiTower(int num, int from, int by, int to) {
	if (num == 1) {
		v.push_back({ from,to });
	}
	else {
		moveHanoiTower(num - 1, from, to, by);
		v.push_back({ from,to });
		moveHanoiTower(num - 1, by, from, to);
	}
}
int main() {
	cin >> n;
	moveHanoiTower(n, 1, 2, 3);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
}