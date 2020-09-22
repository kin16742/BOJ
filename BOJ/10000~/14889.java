import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int n, result = Integer.MAX_VALUE;
	static int[][] s;
	static boolean[] visit;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		s = new int[n][n];
		visit = new boolean[n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				s[i][j] = sc.nextInt();

		combination(visit, 0, n, n / 2);
		System.out.println(result);
	}

	static void combination(boolean[] visited, int start, int m, int r) {
		if (r == 0) {
			compute(visited);
			return;
		}

		for (int i = start; i < m; i++) {
			visited[i] = true;
			combination(visited, i + 1, m, r - 1);
			visited[i] = false;
		}
	}

	static void compute(boolean[] visited) {
		List<Integer> A = new ArrayList<>();
		List<Integer> B = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			if (visited[i])
				A.add(i);
			else
				B.add(i);
		}

		result = Math.min(result, Math.abs(team(A) - team(B)));
	}

	static int team(List<Integer> list) {
		int ret = 0;

		for (int i = 0; i < list.size(); i++)
			for (int j = i + 1; j < list.size(); j++)
				ret += s[list.get(i)][list.get(j)] + s[list.get(j)][list.get(i)];

		return ret;
	}
}
