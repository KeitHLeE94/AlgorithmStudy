package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_2458 {
    static int[][] map;
    static int N;
    static int result;

    public static boolean BFS(int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        boolean[] visit = new boolean[N+1];
        visit[start] = true;

        while(!queue.isEmpty()) {
            int current = queue.poll();

            for(int i=1; i<=N; i++) {
                if(!visit[i] && map[current][i] == 1) {
                    visit[i] = true;
                    queue.add(i);
                }
            }
        }

        queue.add(start);

        while(!queue.isEmpty()) {
            int current = queue.poll();

            for(int i=1; i<=N; i++) {
                if(!visit[i] && map[i][current] == 1) {
                    visit[i] = true;
                    queue.add(i);
                }
            }
        }

        for(int i=1; i<=N; i++) {
            if(!visit[i]) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer NM = new StringTokenizer(br.readLine());
        N = Integer.parseInt(NM.nextToken());
        int M = Integer.parseInt(NM.nextToken());

        map = new int[N+1][N+1];
        result = 0;

        for(int i=0; i<M; i++) {
            StringTokenizer row = new StringTokenizer(br.readLine());

            int from = Integer.parseInt(row.nextToken());
            int to = Integer.parseInt(row.nextToken());

            map[from][to] = 1;
        }

        for(int i=1; i<=N; i++) {
            if(BFS(i)) {
                result++;
            }
        }

        System.out.println(result);
    }
}
