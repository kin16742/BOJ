import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[][] = new int[6][2];
		int k = sc.nextInt();
		int result = 0, w = 0, h = 0, ww = 0, hh = 0;

		for (int i = 0; i < 6; i++) {
			int dir = sc.nextInt();
			int dist = sc.nextInt();

			arr[i][0] = dir;
			arr[i][1] = dist;

			if (dir <= 2)
				w = Math.max(w, dist);
			else
				h = Math.max(h, dist);
		}

		for (int i = 0; i < 6; i++) {
			if (arr[(i + 5) % 6][1] + arr[(i + 1) % 6][1] == w)
				hh = arr[i][1];

			if (arr[(i + 5) % 6][1] + arr[(i + 1) % 6][1] == h)
				ww = arr[i][1];

		}
		
		System.out.println(k * (w * h - ww * hh));
	}

}
