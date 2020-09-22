import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int v, e, k;
	static List<Node>[] graph;
	static int[] distance;
	static boolean[] visit;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	private static class Node implements Comparable<Node> {
		int vertex;
		int totalDistance;

		public Node(int vertex, int totalDistance) {
			this.vertex = vertex;
			this.totalDistance = totalDistance;
		}

		@Override
		public int compareTo(Node o) {
			return this.totalDistance - o.totalDistance;
		}
	}

	public static void main(String[] args) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine().trim());
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(in.readLine());

		distance = new int[v + 1];
		visit = new boolean[v + 1];
		graph = new ArrayList[v + 1];
		
		for (int i = 1; i <= v; i++) 
			graph[i] = new ArrayList<>();
		
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(in.readLine().trim());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			graph[start].add(new Node(end, weight));
		}

		Arrays.fill(distance, Integer.MAX_VALUE);
		distance[k] = 0;

		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		pq.add(new Node(k, 0));

		while (!pq.isEmpty()) {
			Node n = pq.poll();
			int curr = n.vertex;
			int dist = n.totalDistance;

			if (visit[curr])
				continue;

			visit[curr] = true;

			for (Node node : graph[curr]) {
				if (distance[node.vertex] > dist + node.totalDistance) {
					distance[node.vertex] = dist + node.totalDistance;
					pq.add(new Node(node.vertex, distance[node.vertex]));
				}
			}
		}
		for (int i = 1; i <= v; i++) {
			if (distance[i] == Integer.MAX_VALUE)
				System.out.println("INF");
			else
				System.out.println(distance[i]);
		}

	}
}
