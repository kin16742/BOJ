import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[53];
		boolean f = true;

		for (int i = 0; i < n; i++) {
			int temp = sc.nextInt();
			arr[temp]++;
		}

		sc.nextLine();
		String str = sc.nextLine();
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if (c >= 'a' && c <= 'z')
				arr[str.charAt(i) - 'a' + 27]--;

			if (c >= 'A' && c <= 'Z')
				arr[str.charAt(i) - 'A' + 1]--;

			if (c == ' ')
				arr[0]--;
		}

		for (int i = 0; i <= 52; i++) {
			if (arr[i] != 0) {
				f = false;
			}
		}

		if (f)
			System.out.println("y");
		else
			System.out.println("n");
	}

}
