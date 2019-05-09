#include <stdio.h>

int main(void) {
	char arr[100];
	int a, result = 0;
	scanf("%d", &a);
	scanf("%s",arr,a+1);
	for (int i = 0; i<a; i++) {
		result += arr[i]-48;
	}
	printf("%d", result);
	return 0;
}