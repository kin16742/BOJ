import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int k = 0; k < 4; k++) {
			int x1, x2, y1, y2, tx1, tx2, ty1, ty2;
			x1 = sc.nextInt();
			y1 = sc.nextInt();
			x2 = sc.nextInt();
			y2 = sc.nextInt();
			tx1 = sc.nextInt();
			ty1 = sc.nextInt();
			tx2 = sc.nextInt();
			ty2 = sc.nextInt();

			if ((x2 == tx1 && y2 == ty1) || (x1 == tx2 && y2 == ty1) || (x2 == tx1 && y1 == ty2)
					|| (x1 == tx2 && y1 == ty2)) {
				System.out.println('c');
			} else if ((x2 == tx1 && y2 != ty1) || (x1 == tx2 && y2 != ty1) || (x2 != tx1 && y1 == ty2)
					|| (x1 != tx2 && y1 == ty2)) {
				System.out.println('b');
			} else if (x2 < tx1 || tx2 < x1 || y2 < ty1 || ty2 < y1) {
				System.out.println('d');
			} else {
				System.out.println('a');
			}
		}
	}

}
