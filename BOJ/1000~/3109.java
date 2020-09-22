import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

	static int R,C,cnt=0;
	static char[][] map;
	static boolean[][] visited;
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine().trim());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][];
		visited = new boolean[R][C];
		
		for(int i=0; i<R; ++i) {
			map[i] = in.readLine().toCharArray();
		}
		makePipe();
		System.out.println(cnt);
	}
	
	private static void makePipe() {
		cnt = 0;
		for (int i = 0; i <R; i++) {
			visited[i][0] = true;
			dfs(i,0);
		}
	}

	static int[] dr = {-1,0,1};
	private static boolean dfs(int r, int c) {
		if(c==C-1) {
			cnt++;
			return true;
		}
		int nr,nc = c+1;
		for(int d=0; d<3; ++d) {
			nr = r + dr[d];
			if(nr<0 || nr>=R || nc<0 || nc>=C || visited[nr][nc] || map[nr][nc] =='x') continue;
			
			visited[nr][nc] = true;
			if(dfs(nr,nc)) {
				return true;
			}				
		}
		return false;
	}

}
