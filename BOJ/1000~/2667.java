import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector;
import java.util.Arrays;

public class Main {
	static int dy[] = { 0, 0, 1, -1 };
	static int dx[] = { 1, -1, 0, 0 };
	static String s;
	static int n;
	static int arr[][];
	static boolean visit[][];

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
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine();
		n = Integer.parseInt(s);

		arr = new int[n][n];
		visit = new boolean[n][n];
		Queue<Pair> q = new LinkedList<Pair>();
		Queue<Integer> res = new LinkedList<Integer>();
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < n; j++) {
				arr[i][j] = str.charAt(j) - '0';
				if (arr[i][j] == 0)
					visit[i][j] = true;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == false) {
					int temp = 1;
					q.add(new Pair(i, j));

					while (!q.isEmpty()) {
						Pair p = q.poll();
						int y = p.first();
						int x = p.second();
						if (!visit[y][x])
							visit[y][x] = true;

						for (int k = 0; k < 4; k++) {
							int nextY = y + dy[k];
							int nextX = x + dx[k];

							if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n) {
								if (arr[nextY][nextX] == 1 && visit[nextY][nextX] == false) {
									visit[nextY][nextX] = true;
									q.add(new Pair(nextY, nextX));
									temp++;
								}
							}
						}
					}
					res.add(temp);
					cnt++;
				}
			}
		}

		System.out.println(cnt);
        Object[] o = res.toArray();
        Arrays.sort(o);
		for (int i = 0; i < cnt; i++) {
			System.out.println(o[i]);
		}
	}
}