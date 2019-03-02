package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_2352 {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        StringTokenizer temp = new StringTokenizer(br.readLine());

        int[] port = new int[40001];
        int[] DP = new int[40001];

        for(int i=1; i<=N; i++){
            port[i] = Integer.parseInt(temp.nextToken());

            int max = 0;

            for(int j=0; j<i; j++){
                if(port[j] < port[i] && DP[j] > max){
                    max = DP[j];
                }
            }

            DP[i] += max + 1;
        }

        int result = 0;
        for(int i=1; i<=N; i++){
            result = result < DP[i] ? DP[i] : result;
        }

//        for(int i=0; i<=N; i++){
//            System.out.print(DP[i] + " ");
//        }
//        System.out.println();

        System.out.println(result);
    }

}
