import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int n, m;
	static int[][] arr;
	static boolean[][][] visit;
	static int dy[] = { 1, -1, 0, 0 };
	static int dx[] = { 0, 0, 1, -1 };
	static int result = Integer.MAX_VALUE;

	static class Point {
		int y, x, step, crash;

		Point(int y, int x, int step, int crash) {
			this.y = y;
			this.x = x;
			this.step = step;
			this.crash = crash;
		}
	}

	public static void BFS(int y, int x) {
		visit = new boolean[n][m][2];
		visit[0][0][0] = true;
		
		Queue<Point> q = new LinkedList<Point>();
		q.add(new Point(0, 0, 1, 0));
		
		while (!q.isEmpty()) {
			Point p = q.poll();
			int currY = p.y;
			int currX = p.x;
			int step = p.step;
			int crash = p.crash;

			if(currY == n - 1 && currX == m - 1) result = Math.min(result, step);
			
			for (int i = 0; i < 4; i++) {
				int nextY = currY + dy[i];
				int nextX = currX + dx[i];

				if (nextY < n && nextX < m && nextY >= 0 && nextX >= 0) {
					if(arr[nextY][nextX] == 1 && crash == 0) {
						visit[nextY][nextX][crash + 1] = true;
						q.add(new Point(nextY, nextX, step + 1, crash + 1));
					}
					if(arr[nextY][nextX] == 0 && visit[nextY][nextX][crash] == false) {
						visit[nextY][nextX][crash] = true;
						q.add(new Point(nextY, nextX, step + 1, crash));
					}
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		arr = new int[n][m];
		
		for (int i = 0; i < n; i++) {
			char[] temp = sc.next().toCharArray();
			for (int j = 0; j < m; j++) {
				arr[i][j] = temp[j] - '0';
			}
		}

		BFS(0, 0);

		if (result == Integer.MAX_VALUE)
			result = -1;
		System.out.println(result);
	}

}
