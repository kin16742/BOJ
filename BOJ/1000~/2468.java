import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int[] dy = { 0, 0, 1, -1 };
	static int[] dx = { 1, -1, 0, 0 };
	static int[][] arr;
	static int n, max, res, cnt;
	static boolean[][] visit;
	static Queue<Point> q;
	
	public static class Point {
		int y;
		int x;

		Point(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new int[n][n];
		max = 0;
		res = 0;
		q = new LinkedList<Point>();
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = sc.nextInt();
				if (arr[i][j] > max)
					max = arr[i][j];
			}
		}

		for (int k = 0; k <= max; k++) {
			cnt = 0;
			visit = new boolean[n][n];
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] <= k) {
						visit[i][j] = true;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (!visit[i][j]) {
						q.add(new Point(i, j));
						visit[i][j] = true;
						while (!q.isEmpty()) {
							Point p = q.poll();
							int currY = p.y;
							int currX = p.x;
							
							for (int w = 0; w < 4; w++) {
								int nextY = currY + dy[w];
								int nextX = currX + dx[w];

								if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && !visit[nextY][nextX]) {
									visit[nextY][nextX] = true;
									q.add(new Point(nextY, nextX));
								}
							}
						}
						cnt++;
					}
				}
			}
			if (res < cnt)
				res = cnt;
		}
		System.out.println(res);
	}

}
