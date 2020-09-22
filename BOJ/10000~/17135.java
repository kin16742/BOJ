import java.util.Scanner;

public class Main {
	static long arr[][];
	static boolean visit[];
	static long res = 1000000000;

	static void combination(long[][] arr, boolean[] visited, int start, int n, int r) {
		if (r == 0) {
			long temp = calc(arr, visited, n);
			if(res > temp)
				res = temp;
			return;
		}

		for (int i = start; i < n; i++) {
			visited[i] = true;
			combination(arr, visited, i + 1, n, r - 1);
			visited[i] = false;
		}
	}

	static long calc(long[][] arr, boolean[] visited, int n) {
		int sour = 1, sweet = 0;
		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				sour *= arr[i][0];
				sweet += arr[i][1];
			}
		}
		return Math.abs(sour - sweet);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		arr = new long[n][2];
		visit = new boolean[n];
		
		for (int i = 0; i < n; i++) {
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
		}
		for (int i = 1; i <= n; i++) {
			combination(arr, visit, 0, n, i);
		}
		System.out.println(res);
	}

}
