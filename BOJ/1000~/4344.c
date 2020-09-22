#include <stdio.h>
int main(void) {
	int c;
	double n, average = 0, cnt = 0;
	double arr[1000];
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%lf", &n);
		for (int j = 0; j < n; j++) {
			scanf("%lf", &arr[j]);
			average += arr[j];
		}
		average /= n;
		for (int j = 0; j < n; j++) {
			if (arr[j] > average)
				cnt++;
		}
		printf("%.3f%%\n", cnt / n * 100);
		average = 0;
		cnt = 0;
	}
	return 0;
}