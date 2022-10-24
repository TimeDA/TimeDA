import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

public class Solution {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            long N = in.nextLong();
            long K = in.nextLong();
            long max = -1;
            long min = -1;
            SortedMap<Long,Long> map = new TreeMap<Long,Long>();
            map.put(N, 1L);
            while (true) {
                long last = map.lastKey();
                long lastCount = map.remove(last);
                last--;
                long half = last/2;
                Long count = map.get(half);
                if (count == null) count = 0L;
                count += lastCount;
                map.put(half, count);
                long secondHalf = last-half;
                count = map.get(secondHalf);
                if (count == null) count = 0L;
                count += lastCount;
                map.put(secondHalf, count);
                K -= lastCount;
                if (K <= 0) {
                    max = Math.max(half, secondHalf);
                    min = Math.min(half, secondHalf);
                    break;
                }
            }
            
            System.out.println("Case #"+(t+1)+": " + max + " " + min);
        }

    }

}
