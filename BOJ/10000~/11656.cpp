#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
char c[1050];
int main() {
	cin >> c;
	char *s = c;
	vector<string> v;
	for (int i = 0; i < strlen(c); i++) {
		string temp = s + i;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}