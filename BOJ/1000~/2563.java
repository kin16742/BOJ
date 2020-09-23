import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[][] = new int[101][101];
		int n, y, x, result = 0;
		n = sc.nextInt();

		for (int k = 0; k < n; k++) {
			y = sc.nextInt();
			x = sc.nextInt();
			for (int i = y; i < y + 10; i++)
				for (int j = x; j < x + 10; j++)
					arr[i][j] = 1;
		}

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				result += arr[i][j];
		
		System.out.println(result);
	}

}
