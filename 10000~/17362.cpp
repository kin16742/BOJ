#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int arr[8] = { 2,1,2,3,4,5,4,3 };

int main(void) {
	int val;
	cin >> val;
	cout << arr[val % 8] << '\n';
}