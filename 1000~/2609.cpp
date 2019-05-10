#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int a, b, res1, res2;
int D(int x, int y){
	if (max(x, y) % min(x, y) == 0) return min(x, y);
	else return D(min(x, y), max(x, y) % min(x, y));
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	res1 = D(a, b);
	res2 = a * b / res1;
	cout << res1 << '\n' << res2 << '\n';
	return 0;
}