import java.util.*;
 
 public class Main {
 
   public static void main(String args[]) {
     (new Main()).solve();
   }
 
   String res[] = { "X won", "Draw", "O won", "Game has not completed" };
   int X = 0;
   int O = 2;
   int D = 1;
   int OTHER = 3;
 
   String solve(String map[]) {
 
     boolean empty = false;
 
     for(int i=0; i<4; ++i) {
       boolean x = true;
       boolean o = true;
       for(int j=0; j<4; ++j) {
         switch(map[i].charAt(j)) {
         case 'O': x = false; break;
         case 'X': o = false; break;
         case '.': empty = true; x = o = false; break;
         }
       }
       if( x ) { return res[X]; }
       if( o ) { return res[O]; }
       x = o = true;
       for(int j=0; j<4; ++j) {
         switch(map[j].charAt(i)) {
         case 'O': x = false; break;
         case 'X': o = false; break;
         case '.': empty = true; x = o = false; break;
         }
       }
       if( x ) { return res[X]; }
       if( o ) { return res[O]; }
       x = o = true;
       for(int j=0; j<4; ++j) {
         switch(map[j].charAt(j)) {
         case 'O': x = false; break;
         case 'X': o = false; break;
         case '.': empty = true; x = o = false; break;
         }
       }
       if( x ) { return res[X]; }
       if( o ) { return res[O]; }
       x = o = true;
       for(int j=0; j<4; ++j) {
         switch(map[j].charAt(3 - j)) {
         case 'O': x = false; break;
         case 'X': o = false; break;
         case '.': empty = true; x = o = false; break;
         }
       }
       if( x ) { return res[X]; }
       if( o ) { return res[O]; }
     }
 
     if( empty ) { return res[OTHER]; }
     return res[D];
 
   }
 
   void solve() {
 
     Scanner cin = new Scanner(System.in);
 
     int T = cin.nextInt();
     for(int C=1; C<=T; ++C) {
 
       String map[] = new String[4];
       for(int i=0; i<4; ++i) {
         map[i] = cin.next();
       }
 
       System.out.println("Case #" + C + ": " + solve(map));
 
     }
 
   }
 
 }
