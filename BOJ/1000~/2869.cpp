#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int a, b, v;

int main() {
	cin >> a >> b >> v;
	cout << (v - b - 1) / (a - b) + 1;
}