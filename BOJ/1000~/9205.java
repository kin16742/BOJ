import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static boolean[] visit;
	static ArrayList<Integer>[] v;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		while (t-- > 0) {
			int n = sc.nextInt();
			int points[][] = new int[n + 2][2];
			v = new ArrayList[n + 2];
			visit = new boolean[n + 2];

			for (int i = 0; i < n + 2; i++) {
				points[i][0] = sc.nextInt();
				points[i][1] = sc.nextInt();
				v[i] = new ArrayList<>();
			}

			for (int i = 0; i < n + 2; i++) {
				for (int j = 0; j < n + 2; j++) {
					int dist = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
					if (dist <= 1000)
						v[i].add(j);
				}
			}

			dfs(0);

			if (visit[n + 1])
				System.out.println("happy");
			else
				System.out.println("sad");
		}
	}

	static void dfs(int s) {
		visit[s] = true;

		for (int i = 0; i < v[s].size(); i++) {
			if (!visit[v[s].get(i)])
				dfs(v[s].get(i));
		}
	}

}