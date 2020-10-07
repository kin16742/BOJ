import java.util.Scanner;

public class Main {
	static int[] res = new int[2];
	static int[][] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		arr = new int[n][n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = sc.nextInt();

		compute(0, 0, n);
		System.out.println(res[0]);
		System.out.println(res[1]);
	}

	public static void compute(int y, int x, int n) {
		int color = arr[y][x];
		boolean flag = true;

		out: for (int i = y; i < y + n; i++) {
			for (int j = x; j < x + n; j++) {
				if (arr[i][j] != color) {
					flag = false;
					break out;
				}
			}
		}

		if (flag) {
			res[color]++;
		} else {
			compute(y, x, n / 2);
			compute(y + n / 2, x, n / 2);
			compute(y + n / 2, x + n / 2, n / 2);
			compute(y, x + n / 2, n / 2);
		}
	}
}
