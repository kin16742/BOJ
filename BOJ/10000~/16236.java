import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int n, sY, sX, shark = 2, cnt, time;
	static int[] arr;
	static int[][] s;
	static int[] dy = { -1, 0, 0, 1 };
	static int[] dx = { 0, -1, 1, 0 };
	static boolean[][] visit;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		s = new int[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				s[i][j] = sc.nextInt();
				if (s[i][j] == 9) {
					sY = i;
					sX = j;
					s[i][j] = 0;
				}
			}
		}

		while (true) {
			Queue<Point> q = new LinkedList<>();
			List<Point> cand = new ArrayList<>();
			visit = new boolean[n][n];
			int tempY = Integer.MAX_VALUE, tempX = Integer.MAX_VALUE, tempS = Integer.MAX_VALUE, idx = 0;

			q.add(new Point(sY, sX, 0));
			visit[sY][sX] = true;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (s[i][j] > shark)
						visit[i][j] = true;

			while (!q.isEmpty()) {
				Point p = q.poll();
				int currY = p.y;
				int currX = p.x;
				int step = p.step;

				if (s[currY][currX] < shark && s[currY][currX] > 0) {
					cand.add(new Point(currY, currX, step));
					continue;
				}

				for (int i = 0; i < 4; i++) {
					int nextY = currY + dy[i];
					int nextX = currX + dx[i];

					if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n) {
						if (!visit[nextY][nextX]) {
							visit[nextY][nextX] = true;
							q.add(new Point(nextY, nextX, step + 1));
						}
					}
				}
			}
			if (cand.size() == 0)
				break;
			else {
				for (int i = 0; i < cand.size(); i++) {
					Point p = cand.get(i);

					if (tempS > p.step) {
						tempS = p.step;
						tempY = p.y;
						tempX = p.x;
						idx = i;
					} else if (tempS == p.step && tempY > p.y) {
						tempY = p.y;
						tempX = p.x;
						idx = i;
					} else if (tempS == p.step && tempY == p.y && tempX > p.x) {
						tempX = p.x;
						idx = i;
					}
				}
				Point eat = cand.get(idx);
				sY = eat.y;
				sX = eat.x;
				s[sY][sX] = 0;
				cnt++;
				if (cnt == shark) {
					cnt = 0;
					shark++;
				}
				time += eat.step;
			}

		}
		System.out.println(time);
	}

	static public class Point {
		int y, x, step;

		Point(int y, int x, int step) {
			this.y = y;
			this.x = x;
			this.step = step;
		}
	}
}
