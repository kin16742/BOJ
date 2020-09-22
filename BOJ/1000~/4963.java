import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static int dy[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
	static int dx[] = { 1, -1, 0, 1, -1, 0, 1, -1 };
	static String s[];
	static int m, n;
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
		while (true) {
			s = br.readLine().split(" ");
			m = Integer.parseInt(s[0]);
			n = Integer.parseInt(s[1]);

			if (n == 0 && m == 0)
				break;

			arr = new int[n][m];
			visit = new boolean[n][m];
			int res = 0;
			Queue<Pair> q = new LinkedList<Pair>();

			for (int i = 0; i < n; i++) {
				s = br.readLine().split(" ");
				for (int j = 0; j < m; j++) {
					arr[i][j] = Integer.parseInt(s[j]);
					if (arr[i][j] == 0)
						visit[i][j] = true;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (visit[i][j] == false) {
						q.add(new Pair(i, j));
						
						while (!q.isEmpty()) {
							Pair p = q.poll();
							int y = p.first();
							int x = p.second();
							if(!visit[y][x])
								visit[y][x] = true;

							for (int k = 0; k < 8; k++) {
								int nextY = y + dy[k];
								int nextX = x + dx[k];

								if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
									if (arr[nextY][nextX] == 1 && visit[nextY][nextX] == false) {
										visit[nextY][nextX] = true;
										q.add(new Pair(nextY, nextX));
									}
								}
							}
						}
						res++;
					}
				}
			}
			
			System.out.println(res);
		}
	}

}
