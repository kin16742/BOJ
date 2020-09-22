#include <stdio.h>
int main(void) {
	int a, b = 0, left, right, cnt = 0;
	scanf("%d", &a);
	left = a / 10;
	right = a % 10;
	if (a == 0) {
		cnt++;
	}
	while (a != b) {
		left = left + right;
		if (left > 9)
			left -= 10;
		b = right * 10 + left;
		left = b / 10;
		right = b % 10;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}