import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int result = 0, dist = 0;
		int m = sc.nextInt();
		int n = sc.nextInt();
		int k = sc.nextInt();
		int arr[][] = new int[k + 1][2];

		for (int i = 0; i <= k; i++) {
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
		}

		if (arr[k][0] == 1)
			dist = -arr[k][1];
		if (arr[k][0] == 2)
			dist = n + arr[k][1];
		if (arr[k][0] == 3)
			dist = arr[k][1];
		if (arr[k][0] == 4)
			dist = -m - arr[k][1];

		for (int i = 0; i < k; i++) {
			int temp = 0;
			
			if (arr[i][0] == 1)
				temp = -arr[i][1];
			if (arr[i][0] == 2)
				temp = n + arr[i][1];
			if (arr[i][0] == 3)
				temp = arr[i][1];
			if (arr[i][0] == 4)
				temp = -m - arr[i][1];
			
			result += Math.min(Math.abs(dist - temp), 2 * (m + n) - Math.abs(dist - temp));
		}

		System.out.println(result);
	}

}
