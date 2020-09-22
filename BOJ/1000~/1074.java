import java.util.Scanner;

class Main {
	static int n, r, c, res = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		r = sc.nextInt();
		c = sc.nextInt();
		func(n, 0, 0);
		System.out.println(res);
	}

	static void func(int n, int y, int x) {
		if (n == 0)
			return;
		int temp = (int) Math.pow(2, n - 1);

		if (y + temp > r && x + temp > c)
			func(n - 1, y, x);
		else if (y + temp > r && x + temp <= c) {
			res += temp * temp;
			func(n - 1, y, x + temp);
		}
		else if (y + temp <= r && x + temp > c) {
			res += 2 * temp * temp;
			func(n - 1, y + temp, x);
		}
		else if (y + temp <= r && x + temp <= c) {
			res += 3 * temp * temp;
			func(n - 1, y + temp, x + temp);
		}

	}
}