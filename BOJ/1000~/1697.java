import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int n, k;
	static boolean visit[];

	public static class Point {
		int x;
		int s;

		Point(int x, int s) {
			this.x = x;
			this.s = s;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		visit = new boolean[100001];
		Queue<Point> q = new LinkedList<Point>();
		q.add(new Point(n, 0));
		while (!q.isEmpty()) {
			Point p = q.poll();
			int currX = p.x;
			int step = p.s;

			if (currX == k) {
				System.out.println(step);
				break;
			}
			for (int i = 0; i < 3; i++) {
				int next = 0;

				if (i == 0)
					next = currX + 1;
				else if (i == 1)
					next = currX - 1;
				else if (i == 2)
					next = currX * 2;

				if (next >= 0 && next <= 100000) {
					if (visit[next] == false) {
						visit[next] = true;
						q.add(new Point(next, step + 1));
					}
				}
			}
		}
	}

}