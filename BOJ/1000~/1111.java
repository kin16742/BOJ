import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];

		for (int i = 0; i < n; i++)
			arr[i] = sc.nextInt();

		if (n == 1) {
			System.out.println('A');
		} else if (n == 2) {
			if (arr[0] == arr[1])
				System.out.println(arr[1]);
			else
				System.out.println('A');
		} else {
			int x1 = arr[1] - arr[0];
			int x2 = arr[2] - arr[1];
			int a = (x1 != 0) ? x2 / x1 : 0;
			int b = arr[1] - arr[0] * a;

			for (int i = 0; i < n - 1; i++) {
				if (arr[i] * a + b != arr[i + 1]) {
					System.out.println('B');
					System.exit(0);
				}
			}
			System.out.println(arr[n - 1] * a + b);
		}
	}

}
