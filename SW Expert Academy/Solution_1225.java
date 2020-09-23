package ssafy;

import java.util.Scanner;

public class Solution_1225 {
	static int arr[];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int test_case = 1; test_case <= 8; test_case++) {
			int idx = 0, d = 0;

			sc.nextInt();
			arr = new int[8];

			for (int i = 0; i < 8; i++) {
				arr[i] = sc.nextInt();
			}
			while (true) {
				arr[idx % 8] -= (d++ % 5) + 1;
				if (arr[idx % 8] <= 0) {
					arr[idx % 8] = 0;
					break;
				}
				idx++;
			}
			System.out.print("#" + test_case + " ");
			for (int i = idx - 7; i <= idx; i++) {
				System.out.print(arr[i % 8] + " ");
			}
			System.out.println();
		}
	}

}
