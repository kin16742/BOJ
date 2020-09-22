#include <iostream>
using namespace std;
int main() {
	int arr[8];
	bool asc = true, des = true;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 7; i++) {
		if (arr[i + 1] != arr[i] + 1) asc = false;
		if (arr[i + 1] != arr[i] - 1) des = false;
	}
	if (asc)
		cout << "ascending" << endl;
	else if (des)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;
	return 0;
}