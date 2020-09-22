import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static int dy[] = { 0, 0, 1, -1 };
	static int dx[] = { 1, -1, 0, 0 };

	static public class Pair {
		private int a, b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		public int first() {
			return a;
		}

		public int second() {
			return b;
		}
	}

	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int arr[][] = new int[n][m];
		int res = 1;
		Queue<Pair> q = new LinkedList<Pair>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = sc.nextInt();
				if (arr[i][j] == 1) {
					q.add(new Pair(i, j));
				}
			}
		}

		while (!q.isEmpty()) {
			Pair p = q.poll();
			int y = p.first();
			int x = p.second();

			for (int i = 0; i < 4; i++) {
				int nextY = y + dy[i];
				int nextX = x + dx[i];

				if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
					if (arr[nextY][nextX] == 0) {
						arr[nextY][nextX] = arr[y][x] + 1;
						q.add(new Pair(nextY, nextX));
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(arr[i][j] == 0) {
					System.out.println(-1);
					return;
				}
				if(arr[i][j] > res) {
					res = arr[i][j];
				}
			}
		}
		System.out.println(res - 1);
	}

}
