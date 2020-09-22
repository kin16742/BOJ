import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static class Point {
		int y, x;

		Point(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int result = Integer.MAX_VALUE;
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] arr = new int[n][n];
		List<Point> house = new ArrayList<Point>();
		List<Point> chicken = new ArrayList<Point>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = sc.nextInt();
				if (arr[i][j] == 1)
					house.add(new Point(i, j));
				if (arr[i][j] == 2)
					chicken.add(new Point(i, j));
			}
		}

		for (int i = 1; i < (1 << chicken.size()); i++) {
			int temp = i, curr = 0, sum = 0;
			List<Integer> list = new ArrayList<Integer>();

			while (temp != 0) {
				if ((temp & 1) == 1)
					list.add(curr);

				temp >>= 1;
				curr++;
			}

			if (list.size() > m)
				continue;

			for (int j = 0; j < house.size(); j++) {
				int minDist = Integer.MAX_VALUE;
				for (int k = 0; k < list.size(); k++) {
					Point h = house.get(j);
					Point c = chicken.get(list.get(k));
					int dist = Math.abs(h.y - c.y) + Math.abs(h.x - c.x);

					if (minDist > dist)
						minDist = dist;
				}
				sum += minDist;
			}
			if (result > sum)
				result = sum;
		}
		System.out.println(result);
	}

}
