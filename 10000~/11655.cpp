#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <stack>
using namespace std;
string c;
int main(void) {
	char sm = ('a' + 'z') / 2;
	char bi = ('A' + 'Z') / 2;
	getline(cin, c);
	for (int i = 0; i < c.length(); i++) {
		if(c.at(i) >= 'a' && c.at(i) <= 'z'){
			if (c.at(i) > sm) c.at(i) -= 13;
			else c.at(i) += 13;
		}
		if(c.at(i) >= 'A' && c.at(i) <= 'Z'){
			if (c.at(i) > bi) c.at(i) -= 13;
			else c.at(i) += 13;
		}
	}
	cout << c << '\n';
}