import java.util.Scanner;

public class Main {
	static int[][] arr;
	static int n;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new int[n][n];

		for (int i = 0; i < n; i++) {
			String temp = sc.next();
			for (int j = 0; j < n; j++)
				arr[i][j] = temp.charAt(j) - '0';
		}
		func(0, 0, n);
		System.out.println();
	}

	static void func(int y, int x, int k) {
		if (k == 0)
			return;
		int temp = 0;

		for (int i = y; i < y + k; i++) {
			for (int j = x; j < x + k; j++) {
				temp += arr[i][j];
			}
		}
		if (temp == 0)
			System.out.print("0");
		else if (temp == k * k)
			System.out.print("1");
		else {
			int center = k / 2;
			System.out.print("(");
			func(y, x, center);
			func(y, x + center, center);
			func(y + center, x, center);
			func(y + center, x + center, center);
			System.out.print(")");
		}
	}
}