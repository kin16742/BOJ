#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
int n, x;
string str;
stack<int> s;
int main() {
	cin >> n;
	while (n--) {
		cin >> str;
		if (!str.compare("push")) {
			cin >> x;
			s.push(x);
		}
		if (!str.compare("pop")) {
			if (s.empty()) cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		if (!str.compare("size")) {
			cout << s.size() << endl;
		}
		if (!str.compare("empty")) {
			if (s.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		if (!str.compare("top")) {
			if (s.empty()) cout << -1 << endl;
			else cout << s.top() << endl;
		}
	}
}