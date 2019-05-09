#include <stdio.h>

int main(void) {
	int arr[10000];
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i<n; i++) {
		if (arr[i]<x) {
			printf("%d ", arr[i]);
		}
	}
	return 0;
}