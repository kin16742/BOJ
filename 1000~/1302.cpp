#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int n, mx;
string str;
map<string, int> m;
vector<string> v;

int main(void) {
	cin >> n;
	while (n--) {
		cin >> str;
		m[str]++;
	}

	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter) 
		mx = max(mx, (*iter).second);

	for (iter = m.begin(); iter != m.end(); ++iter)
		if (mx == (*iter).second) v.push_back((*iter).first);

	sort(v.begin(), v.end());

	cout << v[0] << '\n';
}