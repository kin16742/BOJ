package ssafy;

import java.util.Scanner;

public class Solution_4301 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int m = sc.nextInt();
			int n = sc.nextInt();
			int cnt = 0;
			boolean[][] arr = new boolean[n][m];

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!arr[i][j]) {
						if (j + 2 < m)
							arr[i][j + 2] = true;
						if (i + 2 < n)
							arr[i + 2][j] = true;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!arr[i][j])
						cnt++;
				}
			}
			System.out.println("#" + test_case + " " + cnt);
		}
	}

}
