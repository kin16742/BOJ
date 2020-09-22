#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

string str;
long long res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 2; i++) {
		int n;

		cin >> str;

		if (str == "black") n = 0;
		else if (str == "brown") n = 1;
		else if (str == "red") n = 2;
		else if (str == "orange") n = 3;
		else if (str == "yellow") n = 4;
		else if (str == "green") n = 5;
		else if (str == "blue") n = 6;
		else if (str == "violet") n = 7;
		else if (str == "grey") n = 8;
		else if (str == "white") n = 9;

		res *= 10;
		res += n;
	}

	cin >> str;

	if (str == "brown") res *= 10;
	else if (str == "red") res *= 100;
	else if (str == "orange") res *= 1000;
	else if (str == "yellow") res *= 10000;
	else if (str == "green") res *= 100000;
	else if (str == "blue") res *= 1000000;
	else if (str == "violet") res *= 10000000;
	else if (str == "grey") res *= 100000000;
	else if (str == "white") res *= 1000000000;

	cout << res << '\n';

	return 0;
}