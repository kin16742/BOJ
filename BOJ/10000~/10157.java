import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws InterruptedException {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int k = sc.nextInt();
		int y = 0, x = 0, dir = 0;
		boolean visit[][] = new boolean[n + 1][m + 1];
		
		if (k > n * m) {
			System.out.println(0);
			k = 0;
		}
		
		while (k > 0) {
			if (k == 1) {
				System.out.println((x + 1) + " " + (y + 1));
				break;
			}
			if (dir % 4 == 0) {
				visit[y][x] = true;
				if (y + 1 < n) {
					if (!visit[y + 1][x]) {
						y++;
						k--;
					} else
						dir++;
				} else
					dir++;
			}
			if (dir % 4 == 1) {
				visit[y][x] = true;
				if (x + 1 < m) {
					if (!visit[y][x + 1]) {
						x++;
						k--;
					} else
						dir++;
				} else
					dir++;
			}
			if (dir % 4 == 2) {
				visit[y][x] = true;
				if (y - 1 >= 0) {
					if (!visit[y - 1][x]) {
						y--;
						k--;
					} else
						dir++;
				} else
					dir++;
			}
			if (dir % 4 == 3) {
				visit[y][x] = true;
				if (x - 1 >= 0) {
					if (!visit[y][x - 1]) {
						x--;
						k--;
					} else
						dir++;
				} else
					dir++;
			}

		}
	}

}
