package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_17070 {
    static class Pipe{
        int frontX, frontY;

        int direction;

        public Pipe(int frontX, int frontY, int direction) {
            this.frontX = frontX;
            this.frontY = frontY;
            this.direction = direction;
        }
    }

    static int[] dx = {0, 1, 1};
    static int[] dy = {1, 1, 0};
    static int[][] map;
    static int N;
    static int count;

    public static void DFS(Pipe start) {
        int currentFrontX = start.frontX;
        int currentFrontY = start.frontY;
        int currentDirection = start.direction;

        if(currentFrontX == N && currentFrontY == N) {
            count++;
            return;
        }

        for(int i=0; i<3; i++) {
            int nextFrontX = currentFrontX + dx[i];
            int nextFrontY = currentFrontY + dy[i];
            int nextDirection = i;

            if((currentDirection == 0 && nextDirection == 2) || (currentDirection == 2 && nextDirection == 0)) {
                continue;
            }

            if(i == 1) {
                if(nextFrontX <= N && nextFrontY <= N) {
                    if(map[nextFrontX][nextFrontY] == 0 && map[currentFrontX][currentFrontY] == 0 && map[nextFrontX][nextFrontY - 1] == 0 && map[currentFrontX][currentFrontY + 1] == 0) {
                        DFS(new Pipe(nextFrontX, nextFrontY, nextDirection));
                    }
                }
            }
            else {
                if(nextFrontX <= N && nextFrontY <= N) {
                    if(map[nextFrontX][nextFrontY] == 0 && map[currentFrontX][currentFrontY] == 0) {
                        DFS(new Pipe(nextFrontX, nextFrontY, nextDirection));
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        count = 0;

        map = new int[N+1][N+1];

        for(int i=1; i<=N; i++) {
            StringTokenizer row = new StringTokenizer(br.readLine());
            for(int j=1; j<=N; j++) {
                map[i][j] = Integer.parseInt(row.nextToken());
            }
        }

        Pipe start = new Pipe(1, 2, 0);

        DFS(start);

        System.out.println(count);
    }

}
