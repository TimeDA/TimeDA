import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t=1; t<=T; t++) {
            int N = in.nextInt();
            int L = in.nextInt();
            int[] C = new int[N];
            int sum = 0;
            for (int l=0; l<L; l++) {
                C[l] = in.nextInt();
                sum += C[l];
            }

            Info[] infos = new Info[N];
            Map<Integer,Integer> map = new HashMap<Integer,Integer>();
            int limit = (N % 2 == 0) ? N/2 : (N+1)/2;
            for (int l=0; l<N; l++) {
                int c = C[l];
                Integer minInt = map.get(c%N);
                if (minInt == null) {
                    int min = 0;
                    while ((min < N) && ((100*(c + min) % N)) < limit) min++;
                    map.put(c%N, min);
                    minInt = min;
                }
                Info info = new Info();
                info.min = minInt;
                info.index = l;
                infos[l] = info;
            }
            Arrays.sort(infos, new Comparator<Info>() {
                public int compare(Info o1, Info o2) {
                    return o1.min - o2.min;
                }
            });
            int remains = N - sum;
            boolean[] used = new boolean[N];
            for (Info info : infos) {
                if (remains >= info.min) {
                    C[info.index] += info.min;
                    used[info.index] = true;
                    remains -= info.min;
                } else {
                    break;
                }
            }
            if (remains > 0) {
                int unused = -1;
                for (int l=0; l<N; l++) {
                    if (!used[l]) unused = l;
                }
                C[unused] += remains;
            }
            int answer = 0;
            for (int value : C) {
                answer += Math.round(100.0*value/N);
            }

            System.out.printf("Case #%d: %s\n", t, answer);
        }
    }

    static class Info {
        int min;
        int index;
    }

}
