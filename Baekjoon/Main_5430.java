package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main_5430 {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for(int test=0; test<T; test++){
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            String temp = br.readLine();
            StringBuilder processed = new StringBuilder();

            for(int i=1; i<temp.length()-1; i++){
                processed.append(temp.charAt(i));
            }

            StringTokenizer input = new StringTokenizer(processed.toString(), ",");

            Deque<String> numbers = new LinkedList<>();

            for(int i=0; i<n; i++){
                numbers.add(input.nextToken());
            }

            boolean reverse = false;
            boolean isError = false;

            for(int i=0; i<p.length(); i++){
                if(p.charAt(i) == 'R'){
                    reverse = !reverse;
                }
                else if(p.charAt(i) == 'D'){
                    if(!numbers.isEmpty()){
                        if(reverse){
                            numbers.pollLast();
                        }
                        else{
                            numbers.pollFirst();
                        }
                    }
                    else{
                        isError = true;
                    }
                }
            }

            if(isError){
                System.out.println("error");
            }
            else{
                StringBuilder result = new StringBuilder();
                result.append("[");

                while(!numbers.isEmpty()){
                    if(reverse){
                        result.append(numbers.pollLast());
                        result.append(",");
                    }
                    else{
                        result.append(numbers.pollFirst());
                        result.append(",");
                    }
                }

                if(result.length() > 2){
                    result.deleteCharAt(result.length()-1);
                }
                result.append("]");

                System.out.println(result);
            }
        }
    }
}
