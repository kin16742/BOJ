#include <iostream>
using namespace std;
int main() {
	char arr[80];
	int t, result;
	cin >> t;
	while (t--) {
		cin >> arr;
		int i = 0;
		int score = 1;
		result = 0;
		while (arr[i] != NULL) {
			if (arr[i] == 'O') {
				result += score;
				score++;
			}
			else
				score = 1;
			i++;
		}
		cout << result << endl;
	}
	return 0;
}