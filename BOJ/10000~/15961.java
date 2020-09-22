import java.util.Scanner;

public class Main {
	static int n, d, k, c, cnt, result;
	static int[] arr;
	static int[] chk;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		d = sc.nextInt();
		k = sc.nextInt();
		c = sc.nextInt();
		arr = new int[n];
		chk = new int[d + 1];

		for (int i = 0; i < n; i++)
			arr[i] = sc.nextInt();

		for (int i = 0; i < k; i++) {
			if (chk[arr[i]] == 0)
				cnt++;
			chk[arr[i]]++;
		}

		if (chk[c] == 0)
			result = Math.max(result, cnt + 1);
		else
			result = Math.max(result, cnt);

		for (int i = k; i < n + k; i++) {
			chk[arr[(i - k) % n]]--;
			if (chk[arr[(i - k) % n]] == 0)
				cnt--;
			if (chk[arr[i % n]] == 0)
				cnt++;
			chk[arr[i % n]]++;

			if (chk[c] == 0)
				result = Math.max(result, cnt + 1);
			else
				result = Math.max(result, cnt);
		}
		System.out.println(result);
	}

}
