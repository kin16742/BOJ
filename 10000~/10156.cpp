#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <stack>
using namespace std;
int a, b, c;
int main(void) {
	cin >> a >> b >> c;
	if (a*b > c) cout << a * b - c << '\n';
	else cout << 0 << '\n';
}