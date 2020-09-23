package ssafy;

public class Solution_1238 {
	static void combination(boolean[] visited, int start, int m, int r) {
		if (r == 0) {
			// 조합 결과
			print(visited, m);
			return;
		}

		for (int i = start; i < m; i++) {
			visited[i] = true;
			combination(visited, i + 1, m, r - 1);
			visited[i] = false;
		}
	}

	static void print(boolean[] visited, int m) {
		for (int i = 0; i < m; i++)
			if (visited[i])
				System.out.print(i + " ");
		System.out.println();
	}

	public static void main(String[] args) {
		boolean[] visit = new boolean[6];
		combination(visit, 0, 6, 3);
		// nCr n r
	}

}
