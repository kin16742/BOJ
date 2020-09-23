import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		int dp[][] = new int[n][2];
		int result = 0;
		
		for (int i = 0; i < n; i++)
			arr[i] = sc.nextInt();

		dp[0][0] = 1;
		dp[0][1] = 1;

		for (int i = 1; i < n; i++) {
			if (arr[i] >= arr[i - 1])
				dp[i][0] = dp[i - 1][0] + 1;
			else
				dp[i][0] = 1;
			
			if (arr[i] <= arr[i - 1])
				dp[i][1] = dp[i - 1][1] + 1;
			else
				dp[i][1] = 1;

		}

		for (int i = 0; i < n; i++) {
			result = Math.max(result, dp[i][0]);
			result = Math.max(result, dp[i][1]);
		}
		
		System.out.println(result);
	}

}
