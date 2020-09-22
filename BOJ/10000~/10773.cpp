#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <stack>
using namespace std;
int n, m, res;
stack<int> s;
int main(void) {
	cin >> n;
	while (n--) {
		cin >> m;
		if (m == 0) s.pop();
		else s.push(m);
	}
	while (!s.empty()) {
		res += s.top();
		s.pop();
	}
	cout << res << '\n';
}