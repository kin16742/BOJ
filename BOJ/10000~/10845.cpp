#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, x;
queue<int> q;
string str;
int main() {
	cin >> n;
	while (n--) {
		cin >> str;
		if (!str.compare("push")) {
			cin >> x;
			q.push(x);
		}
		if (!str.compare("pop")) {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		if (!str.compare("size")) {
			cout << q.size() << endl;
		}
		if (!str.compare("empty")) {
			if (q.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		if (!str.compare("front")) {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
			}
		}
		if (!str.compare("back")){
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.back() << endl;
			}
		}
	}
}