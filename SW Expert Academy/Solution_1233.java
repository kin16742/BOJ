package ssafy;

import java.util.Scanner;

public class Solution_1233 {
	static String[] arr;
	static int n;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int test_case = 1; test_case <= 10; test_case++) {
			n = sc.nextInt();
			sc.nextLine();
			arr = new String[n + 1];
			for (int i = 1; i <= n; i++) {
				String[] temp = sc.nextLine().split(" ");
				arr[i] = temp[1];
			}
			if (solve(1))
				System.out.println("#" + test_case + " " + 1);
			else
				System.out.println("#" + test_case + " " + 0);

		}
	}

	public static boolean solve(int idx) {
		if (arr[idx].equals("+") || arr[idx].equals("-") || arr[idx].equals("*") || arr[idx].equals("/")) {
			if (idx * 2 + 1 <= n)
				return solve(idx * 2) && solve(idx * 2 + 1);
			else
				return false;

		} else {
			if (idx * 2 + 1 <= n)
				return solve(idx * 2) && solve(idx * 2 + 1);
			else
				return true;

		}
	}
}
