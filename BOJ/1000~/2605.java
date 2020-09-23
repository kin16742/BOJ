import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, k;
		n = sc.nextInt();
		
		LinkedList<Integer> list = new LinkedList<>();

		k = sc.nextInt();
		list.add(k, 1);
		
		for (int i = 2; i <= n; i++) {
			k = sc.nextInt();
			list.add(list.size() - k, i);
		}
		
		for(int i : list)
			System.out.print(i + " ");
	}

}
