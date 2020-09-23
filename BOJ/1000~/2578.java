import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[][] = new int[5][5];
		int num[] = new int[25];

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				arr[i][j] = sc.nextInt();

		for (int i = 0; i < 25; i++)
			num[i] = sc.nextInt();

		for (int k = 0; k < 25; k++) {
			int sum[] = new int[12];
			int cnt = 0;

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					if (arr[i][j] == num[k])
						arr[i][j] = 0;

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					sum[i] += arr[i][j];

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					sum[5 + i] += arr[j][i];

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					sum[10] += arr[i][i];

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					sum[11] += arr[i][4 - i];

			for (int i = 0; i < 12; i++) {
				if (sum[i] == 0)
					cnt++;
			}
			
			if (cnt >= 3) {
				System.out.println(k + 1);
				break;
			}
		}
	}

}
