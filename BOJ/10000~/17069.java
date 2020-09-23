import java.util.Scanner;

public class Main {
	static long dp[][][][];
	static int arr[][];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		dp = new long[n][n][n][n];
		arr = new int[n][n];
		dp[0][0][0][1] = 1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = sc.nextInt();

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (j + 1 < n && arr[i][j + 1] == 0)
					dp[i][j][i][j + 1] += dp[i][j - 1][i][j];
				if (i + 1 < n && j + 1 < n && arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0)
					dp[i][j][i + 1][j + 1] += dp[i][j - 1][i][j];

				if (i > 0) {
					if (i + 1 < n && arr[i + 1][j] == 0)
						dp[i][j][i + 1][j] += dp[i - 1][j][i][j];
					if (i + 1 < n && j + 1 < n && arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0)
						dp[i][j][i + 1][j + 1] += dp[i - 1][j][i][j];
				}
				if (i > 0 && j > 0) {
					if (j + 1 < n && arr[i][j + 1] == 0)
						dp[i][j][i][j + 1] += dp[i - 1][j - 1][i][j];
					if (i + 1 < n && j + 1 < n && arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0)
						dp[i][j][i + 1][j + 1] += dp[i - 1][j - 1][i][j];
					if (i + 1 < n && arr[i + 1][j] == 0)
						dp[i][j][i + 1][j] += dp[i - 1][j - 1][i][j];
				}
			}
		}
		System.out.println(
				dp[n - 2][n - 2][n - 1][n - 1] + dp[n - 2][n - 1][n - 1][n - 1] + dp[n - 1][n - 2][n - 1][n - 1]);
	}

}
