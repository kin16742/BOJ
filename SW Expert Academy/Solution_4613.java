package ssafy;

import java.util.Scanner;

public class Solution_4613 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int arr[][] = new int[n][3];
			int dp[] = new int[n];

			for (int i = 0; i < n; i++) {
				String temp = sc.next();
				for (int j = 0; j < temp.length(); j++) {
					if (temp.charAt(j) == 'W')
						arr[i][0]++;
					if (temp.charAt(j) == 'B')
						arr[i][1]++;
					if (temp.charAt(j) == 'R')
						arr[i][2]++;
				}
			}
			
			dp[0] = arr[0][1] + arr[0][2];
			dp[n - 1] = arr[n - 1][0] + arr[n - 1][1];
			int res = Integer.MAX_VALUE;
			for (int i = 1; i < n - 1; i++) {
				for (int j = i; j < n - 1; j++) {
					int temp = 0;
					for (int k = 1; k < n - 1; k++) {
						if (k < i)
							temp += arr[k][1] + arr[k][2];
						else if (k >= i && k <= j)
							temp += arr[k][0] + arr[k][2];
						else if (k > j)
							temp += arr[k][0] + arr[k][1];
					}
					res = Math.min(res, temp);
				}
			}
			System.out.println("#" + test_case + " " + (res + dp[0] + dp[n - 1]));
		}
	}

}
