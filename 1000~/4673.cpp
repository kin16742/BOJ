#include <iostream>
using namespace std;
int sol(int n) {
	int sum = n;
	while (1) {
		if(n == 0) break;
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}
int main() {
	int arr[10001] = { 0 };
	for (int i = 1; i < 10001; i++) {
		int a = sol(i);
		if (a <= 10000) {
			arr[a] = 1;
		}
	}
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}