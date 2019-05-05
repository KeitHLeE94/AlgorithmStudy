package MockTest;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_2115 {
    static int[][] map;
    static int N, M, C;

    public static class Profit{
        int profit;
        boolean visit[][] = new boolean[N][N];
    }

    public static void DFS(int index, int set[], boolean used[], Profit candidate){
        if(index == set.length){
            int weightSum = 0;
            int profitSum = 0;

            for(int i=0; i<used.length; i++){
                if(used[i]){
                    weightSum += set[i];
                    profitSum += set[i] * set[i];
                }
            }

            if(weightSum <= C){
                if(candidate.profit < profitSum){
                    candidate.profit = profitSum;
                }
            }

            return;
        }

        used[index] = true;
        DFS(index+1, set, used, candidate);
        used[index] = false;
        DFS(index+1, set, used, candidate);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for(int test=1; test<=T; test++){
            StringTokenizer temp = new StringTokenizer(br.readLine());

            N = Integer.parseInt(temp.nextToken());
            M = Integer.parseInt(temp.nextToken());
            C = Integer.parseInt(temp.nextToken());

            map = new int[N][N];

            for(int i=0; i<N; i++){
                StringTokenizer row = new StringTokenizer(br.readLine());

                for(int j=0; j<N; j++){
                    map[i][j] = Integer.parseInt(row.nextToken());
                }
            }

            List<Profit> profits = new ArrayList<>();

            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(j+M-1 < N){
                        Profit p = new Profit();

                        int weightSum = 0;
                        int profitSum = 0;
                        boolean visit[][] = new boolean[N][N];

                        for(int k=j; k<j+M; k++){
                            visit[i][k] = true;
                            weightSum += map[i][k];
                            profitSum += map[i][k] * map[i][k];
                        }

                        if(weightSum <= C){
                            p.profit = profitSum;
                            p.visit = visit;

                            profits.add(p);
                        }
                        else{
                            Profit candidate = new Profit();
                            candidate.visit = visit;

                            int set[] = new int[M];
                            boolean used[] = new boolean[M];

                            for(int k=j; k<j+M; k++){
                                set[k-j] = map[i][k];
                            }

                            DFS(0, set, used, candidate);

                            profits.add(candidate);
                        }
                    }
                }
            }

            int maxProfit = 0;

            for(int i=0; i<profits.size(); i++){
                for(int j=0; j<profits.size(); j++){
                    if(i == j){
                        continue;
                    }

                    boolean visit1[][] = profits.get(i).visit;
                    boolean visit2[][] = profits.get(j).visit;

                    boolean available = true;

                    for(int k=0; k<N; k++){
                        for(int l=0; l<N; l++){
                            if(visit1[k][l] && visit2[k][l]){
                                available = false;
                                break;
                            }
                        }
                    }

                    if(available){
                        int tempResult = profits.get(i).profit + profits.get(j).profit;

                        maxProfit = maxProfit < tempResult ? tempResult : maxProfit;
                    }
                }
            }

            System.out.println("#" + test + " " + maxProfit);
        }

    }
}
