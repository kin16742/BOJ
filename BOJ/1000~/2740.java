import java.util.Scanner;

public class Main {
	static int[][][] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		arr = new int[2][100][100];
		int n[] = new int[2];
		int m[] = new int[2];
		for (int k = 0; k < 2; k++) {
			n[k] = sc.nextInt();
			m[k] = sc.nextInt();

			for (int i = 0; i < n[k]; i++)
				for (int j = 0; j < m[k]; j++)
					arr[k][i][j] = sc.nextInt();
		}

		for (int i = 0; i < n[0]; i++) {
			for (int j = 0; j < m[1]; j++) {
				int temp = 0;
				for (int k = 0; k < n[1]; k++) {
					temp += arr[0][i][k] * arr[1][k][j];
				}
				System.out.print(temp + " ");
			}
			System.out.println();
		}
	}
}
