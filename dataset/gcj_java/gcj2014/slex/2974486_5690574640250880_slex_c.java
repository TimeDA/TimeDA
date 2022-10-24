
 import java.io.BufferedInputStream;
 import java.io.FileInputStream;
 import java.io.InputStream;
 import java.util.*;
 
 import static java.lang.Math.*; 
 import static java.util.Arrays.*;
 import static java.lang.Integer.*;
 import static java.lang.Character.*;  
 
 
 
 public class C {
 
 	Scanner scan;
 
 	
 	
 	int intLine(){
 		return parseInt(scan.nextLine());
 	}
 	
 	int get(int x, int y, boolean[][]F){
 	  if(x<0||x==F.length)return -1;
 	  if(y<0||y==F[0].length)return -1;
 	  if(F[x][y])return 0;
 	  return 1;
 	}
 	boolean check(boolean[][]F){
 	  int[][]z = new int[F.length][F[0].length];
 	  for(int i=0;i<z.length;i++)for(int j=0;j<z[0].length;j++){
 	    if(!F[i][j])continue;
 	    for(int a=-1;a<2;a++)for(int b=-1;b<2;b++){
 	      int g = get(i+a, j+b, F);
 	      if(g!=-1)z[i][j]+=g;
 	    }
 	  }
 	  for(int i=0;i<F.length;i++)for(int j=0;j<F[0].length;j++){
 	    if(!F[i][j])continue;
 	    if(z[i][j]==0)continue;
 	    boolean ok = false;
 	    for(int a=-1;a<2;a++)for(int b=-1;b<2;b++){
 	      if(get(i+a, b+j, F)!=-1 && z[i+a][b+j]==0 &&F[i+a][j+b])ok = true;
 	    }
 	    if(!ok)return false;
 	  }
 	  return true;
 	}
 	
 	
 	String print(boolean[][]F) {
 	  String r = "\n";
 	  for(int i=0;i<F.length;i++){
 	    for(int j=0;j<F[0].length;j++){
 	      if(i==0 && j==0)r+='c';
 	      else if(F[i][j])r+='.';
 	      else r+='*';
 	    }
 	    
 	    if(i+1!=F.length)r+="\n";
 	  }
 	  return r;
 	}
 	String solve(){
 	  int n = scan.nextInt();
 	  int m = scan.nextInt();
 	  int b = scan.nextInt();
 	  int f = n*m-b;
 	  if(f==1){
 	    boolean[][]F = new boolean[n][m];
 	    F[0][0]=true;
 	    return print(F);
 	  }
 	  for(int r=1;r<=n && r<= f;r++ ) {
 	    boolean[][]F = new boolean[n][m];
 	    int c = (f+r-1)/r;
 	    if(c>m)continue;
 	    int left = f;
 	    for(int i=0;i<r;i++)for(int j=0;j<c;j++){
 	      if(left ==0)break;
 	      left--;
 	      F[i][j]=true;
 	    }
 	    if(check(F))return print(F);
 	  }
 		return "\nImpossible";
 	}
 	
 	void solveAll(){
 		int N = parseInt(scan.nextLine());
 		for(int i=0;i<N;i++){
 			String r =solve();
 			System.out.format("Case #%d: %s\n",i+1,r);
 		}
 	}
 	
 	C() throws Exception{
 		String cn = C.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt0.in";
 		String largeName = cn+"-large.in";
 		InputStream in = new BufferedInputStream(new FileInputStream(smallName));
 		scan = new Scanner(in);
 	}
 
 	
 
 	public static void main(String[] args) throws Exception{
 	    Locale.setDefault(Locale.US); 
 	    new C().solveAll();
 	   
 	}
 
 }
