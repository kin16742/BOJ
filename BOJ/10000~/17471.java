import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int n, result = Integer.MAX_VALUE;
	static int[] p;
	static List<Integer>[] graph;
	static boolean[] visit, comb;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		p = new int[n + 1];
		graph = new ArrayList[n + 1];
		comb = new boolean[n + 1];

		for (int i = 1; i <= n; i++)
			graph[i] = new ArrayList<>();

		for (int i = 1; i <= n; i++)
			p[i] = sc.nextInt();

		for (int i = 1; i <= n; i++) {
			int temp = sc.nextInt();
			for (int j = 0; j < temp; j++) {
				int adj = sc.nextInt();
				graph[i].add(adj);
			}
		}
		for (int i = 1; i <= n; i++)
			combination(comb, 1, n + 1, i);
		
		if(result == Integer.MAX_VALUE)
			result = -1;
		System.out.println(result);
	}

	static public void combination(boolean[] visited, int start, int m, int r) {
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

	static public void compute(boolean[] visited) {
		if (checkConnect(visited, true) && checkConnect(visited, false)) {
			int sumA = 0, sumB = 0;
			for (int i = 1; i <= n; i++) {
				if (visited[i])
					sumA += p[i];
				if (!visited[i])
					sumB += p[i];
			}
			result = Math.min(result, Math.abs(sumA - sumB));
		}
	}

	static public boolean checkConnect(boolean[] visited, boolean chk) {
		boolean[] visitTemp = new boolean[n + 1];
		int start = -1;

		for (int i = 1; i <= n; i++) {
			if (visited[i] != chk)
				visitTemp[i] = true;
			else
				start = i;
		}
		
		if (start == -1)
			return false;

		dfs(start, visitTemp);

		for (int i = 1; i <= n; i++)
			if (visitTemp[i] == false)
				return false;

		return true;
	}

	static public void dfs(int s, boolean[] visited) {
		visited[s] = true;

		
		for (int i = 0; i < graph[s].size(); i++) {
			int next = graph[s].get(i);
			if (!visited[next])
				dfs(next, visited);
		}
	}
}
