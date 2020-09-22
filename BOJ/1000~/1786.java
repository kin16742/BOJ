import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static String T, P;
	static int[] failure;

	static void fail(String str) {
		for (int i = 1, j = 0; i < str.length(); ++i) {
			while (j > 0 && str.charAt(i) != str.charAt(j))
				j = failure[j - 1];

			if (str.charAt(i) == str.charAt(j))
				failure[i] = ++j;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		List<Integer> list = new ArrayList<>();

		T = sc.nextLine();
		P = sc.nextLine();
		failure = new int[P.length()];

		fail(P);

		for (int i = 0, j = 0; i < T.length(); i++) {
			while (j > 0 && T.charAt(i) != P.charAt(j))
				j = failure[j - 1];

			if (T.charAt(i) == P.charAt(j)) {
				if (j == P.length() - 1) {
					list.add(i - P.length() + 2);
					j = failure[j];
				} else
					j++;
			}
		}

		System.out.println(list.size());
		for (int i = 0; i < list.size(); i++)
			System.out.print(list.get(i) + " ");
		System.out.println();
	}

}
