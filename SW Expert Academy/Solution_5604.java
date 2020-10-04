
import java.util.Scanner;

public class Solution_5604 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			long answer[] = new long[10];
			long point = 1;
			long res = 0;

			while (a <= b) {
				while (b % 10 != 9 && a <= b) {
					calc(answer, b, point);
					b--;
				}
				
				if (a > b)
					break;

				while (a % 10 != 0 && a <= b) {
					calc(answer, a, point);
					a++;
				}
				
				a /= 10;
				b /= 10;
				
				for (int i = 0; i < 10; i++) 
					answer[i] += (b - a + 1) * point;
				
				point *= 10;
			}
			for (int i = 0; i < 10; i++)
				res += i * answer[i];

			System.out.println("#" + test_case + " " + res);
		}
	}

	public static void calc(long[] arr, long num, long point) {
		while (true) {
			arr[(int) (num % 10)] += point;
			num /= 10;
			if (num == 0)
				break;
		}
	}
}
