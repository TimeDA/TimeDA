import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
       double res = solve(cin.nextDouble(), cin.nextDouble(), cin.nextDouble());
       System.out.println("Case #" + C + ": " + res);
     }
 
   }
 
   double solve(double C, double F, double X) {
 
     double gen = 2;
     double ret = X / gen;
 
     double cur = 0;
 
     while( ret > cur ) {
       cur += C / gen;
       gen += F;
       ret = Math.min(ret, cur + X / gen);
     }
 
     return ret;
 
   }
 
 }
