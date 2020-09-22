#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[202];
int ball[5], small, big;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ball[1] = 1;
	ball[4] = 2;
	cin >> s;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'A')
			swap(ball[1], ball[2]);
		if (s[i] == 'B')
			swap(ball[1], ball[3]);
		if (s[i] == 'C')
			swap(ball[1], ball[4]);
		if (s[i] == 'D')
			swap(ball[2], ball[3]);
		if (s[i] == 'E')
			swap(ball[2], ball[4]);
		if (s[i] == 'F')
			swap(ball[3], ball[4]);
	}
	for (int i = 1; i < 5; i++) {
		if (ball[i] == 1) small = i;
		if (ball[i] == 2) big = i;
	}
	cout << small << '\n' << big << '\n';
	return 0;
}
