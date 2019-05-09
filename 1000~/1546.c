#include <stdio.h>
int main(void) {
	int a = 0;
	double arr[1000];
	double temp = 0;
	double max = 0;
	double result = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%lf", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}
	for (int i = 0; i < a; i++) {
		result += (arr[i] / max) * 100;
	}
	result /= a;
	printf("%.2f\n", result);
	return 0;
}