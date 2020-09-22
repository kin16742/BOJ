import java.util.Scanner;

public class Main {
	static int[][] arr;
	static int result = Integer.MAX_VALUE, n, m, k;
	static int dy[] = { 1, 0, -1, 0 };
	static int dx[] = { 0, 1, 0, -1 };

	static class Operation {
		int y, x, r;

		Operation(int y, int x, int r) {
			this.y = y;
			this.x = x;
			this.r = r;
		}
	}

	static void permutation(Operation[] o, int depth, int n, int r) {
		if (depth == r) {
			compute(o, r);
			return;
		}

		for (int i = depth; i < n; i++) {
			swap(o, depth, i);
			permutation(o, depth + 1, n, r);
			swap(o, depth, i);
		}
	}

	static void compute(Operation[] o, int r) {
		int[][] temp = new int[n][m];
		int min = Integer.MAX_VALUE;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				temp[i][j] = arr[i][j];

		for (int i = 0; i < r; i++) {
			rotate(temp, o[i]);
		}

		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += temp[i][j];
			}
			if (min > sum)
				min = sum;
		}
		if(result > min)
			result = min;
	}

	static void rotate(int[][] arr, Operation o) {
		int y = o.y;
		int x = o.x;

		for (int round = 1; round <= o.r; round++) {
			int tempY = y - round;
			int tempX = x - round;
			for (int d = 0; d < 4; d++) {
				for (int j = 0; j < round * 2; j++) {
					int nextY = tempY + dy[d];
					int nextX = tempX + dx[d];

					swap(arr, tempY, tempX, nextY, nextX);

					tempY = nextY;
					tempX = nextX;
				}
			}
			swap(arr, tempY, tempX, tempY, tempX + 1);
		}
	}

	static void swap(int[][] arr, int aY, int aX, int bY, int bX) {
		int temp = arr[aY][aX];
		arr[aY][aX] = arr[bY][bX];
		arr[bY][bX] = temp;
	}

	static void swap(Operation[] o, int a, int b) {
		Operation temp = o[a];
		o[a] = o[b];
		o[b] = temp;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		arr = new int[n][m];
		Operation[] op = new Operation[k];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < k; i++) {
			int tempY = sc.nextInt();
			int tempX = sc.nextInt();
			int tempR = sc.nextInt();
			op[i] = new Operation(tempY - 1, tempX - 1, tempR);
		}

		permutation(op, 0, k, k);
		
		System.out.println(result);
	}

}
