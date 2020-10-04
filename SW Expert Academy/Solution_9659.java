
import java.util.Scanner;

public class Solution_9659 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int calc[][] = new int[n - 1][3];
			for (int i = 0; i < n - 1; i++) {
				calc[i][0] = sc.nextInt();
				calc[i][1] = sc.nextInt();
				calc[i][2] = sc.nextInt();
			}
			long ans[] = new long[n + 1];
			ans[0] = 1;
			int m = sc.nextInt();
			System.out.print("#" + test_case + " ");
			for (int i = 0; i < m; i++) {
				int num = sc.nextInt();
				ans[1] = num;
				for (int j = 2; j <= n; j++) {
					if (calc[j - 2][0] == 1) {
						ans[j] = (ans[calc[j - 2][1]] + ans[calc[j - 2][2]]) % 998244353;
					}
					if (calc[j - 2][0] == 2) {
						ans[j] = (calc[j - 2][1] * ans[calc[j - 2][2]]) % 998244353 ;
					}
					if (calc[j - 2][0] == 3) {
						ans[j] = (ans[calc[j - 2][1]] * ans[calc[j - 2][2]]) % 998244353;
					}
				}
				System.out.print(ans[n] + " ");
			}
			System.out.println();
		}
	}

}
