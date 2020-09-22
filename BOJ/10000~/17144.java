import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int r, c, t, res = 0;
	static int[][] arr;
	static Point[] cleaner;
	static int[] dy = { -1, 1, 0, 0 };
	static int[] dx = { 0, 0, -1, 1 };
	static int dirUp[] = { 0, 3, 1, 2 };
	static int dirDown[] = { 1, 3, 0, 2 };
	static int dir[][] = { dirUp, dirDown };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		r = sc.nextInt();
		c = sc.nextInt();
		t = sc.nextInt();
		arr = new int[r][c];
		cleaner = new Point[2];
		int cleanerIdx = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = sc.nextInt();
				if (arr[i][j] == -1)
					cleaner[cleanerIdx++] = new Point(i, j);
			}
		}

		while (t-- > 0) {
			spread();
			clean();
		}

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				res += arr[i][j];

		System.out.println(res + 2);

	}

	static class Point {
		int y, x;

		Point(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	static void spread() {
		List<Point> list = new ArrayList<>();
		int calc[][] = new int[r][c];

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (arr[i][j] >= 5)
					list.add(new Point(i, j));

		for (Point p : list) {
			int val = arr[p.y][p.x] / 5;

			for (int i = 0; i < 4; i++) {
				int nextY = p.y + dy[i];
				int nextX = p.x + dx[i];

				if (nextY >= 0 && nextY < r && nextX >= 0 && nextX < c) {
					if (arr[nextY][nextX] >= 0) {
						calc[nextY][nextX] += val;
						calc[p.y][p.x] -= val;
					}
				}
			}
		}

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				arr[i][j] += calc[i][j];

	}

	static void clean() {
		for (int i = 0; i < 2; i++) {
			int[] d = dir[i];
			int y = cleaner[i].y + dy[d[0]];
			int x = cleaner[i].x;
			arr[y][x] = 0;
			for (int j = 0; j < 4; j++) {
				while (true) {
					int nextY = y + dy[d[j]];
					int nextX = x + dx[d[j]];

					if (nextY >= 0 && nextY < r && nextX >= 0 && nextX < c) {
						if (nextY == cleaner[i].y + dy[d[2]] || arr[nextY][nextX] == -1)
							break;
						else {
							swap(y, x, nextY, nextX);
							y = nextY;
							x = nextX;
						}
					} else
						break;
				}
			}
		}
	}

	static void swap(int aY, int aX, int bY, int bX) {
		int temp = arr[aY][aX];
		arr[aY][aX] = arr[bY][bX];
		arr[bY][bX] = temp;
	}

}
