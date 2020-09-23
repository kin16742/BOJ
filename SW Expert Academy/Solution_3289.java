package ssafy;

import java.util.Scanner;

public class Solution_3289 {
	static int arr[];

	static int find(int a) {
		if (arr[a] == a)
			return a;
		return arr[a] = find(arr[a]);
	}

	static boolean union(int a, int b) {
		int aRoot = find(a);
		int bRoot = find(b);
		if (aRoot == bRoot)
			return false;

		arr[bRoot] = aRoot;
		return true;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		boolean[] chk = new boolean[n + 1];
		arr = new int[n + 1];
		int cnt = 0;

		for (int i = 1; i <= n; i++)
			arr[i] = i;

		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();

			union(a, b);
		}
		for (int i = 1; i <= n; i++) {
			chk[arr[i]] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (chk[i])
				cnt++;
		}
		System.out.println(cnt);
	}

}
