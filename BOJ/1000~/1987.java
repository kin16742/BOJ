import java.util.Scanner;

public class Main {
	static int r, c, cnt;
	static char[][] arr;
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };
	static boolean[] visit;

	static void DFS(int y, int x, int s) {
		visit[arr[y][x] - 'A'] = true;
		cnt = Math.max(cnt, s);

		for (int i = 0; i < 4; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if (nextY >= 0 && nextY < r && nextX >= 0 && nextX < c) {
				if (!visit[arr[nextY][nextX] - 'A']) {
					DFS(nextY, nextX, s + 1);
					visit[arr[nextY][nextX] - 'A'] = false;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		r = sc.nextInt();
		c = sc.nextInt();
		arr = new char[r][];
		visit = new boolean[26];
		for (int i = 0; i < r; i++)
			arr[i] = sc.next().toCharArray();
		DFS(0, 0, 1);
		System.out.println(cnt);
	}

}
