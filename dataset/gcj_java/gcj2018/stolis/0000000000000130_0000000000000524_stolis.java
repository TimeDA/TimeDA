import java.util.Scanner;

public class Solution {
    
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            double D = in.nextDouble();
            int N = in.nextInt();
            double maxTime = 0;
            for (int n=0; n<N; n++) {
                double K = in.nextDouble();
                double S = in.nextDouble();
                double time = (D-K)/S;
                maxTime = Math.max(time, maxTime);
            }
            double speed = D/maxTime;
            
            System.out.println("Case #"+(t+1)+": " + speed);
        }
    }

}
