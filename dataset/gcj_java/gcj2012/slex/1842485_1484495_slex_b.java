import java.io.BufferedInputStream;
 import java.io.FileInputStream;
 import java.io.InputStream;
 import java.util.*;
 
 import static java.lang.Math.*; 
 import static java.util.Arrays.*;
 import static java.lang.Integer.*;
 import static java.lang.Character.*;  
 
 
 class matt implements Comparable<matt>{
 	static int W;
 	static int L;
 	int w; int l;
 	int x, y;
 	
 	matt(int w, int l, int x, int y){
 		this.w=w;this.l=l;
 		this.x = x;this.y=y;
 	}
 	int getM(){
 		int w = this.w;
 		int l = this.l;
 		
 		if(x==0 && l==L){
 			l = Integer.MAX_VALUE;
 		}else if(x==0|| x+l==L){
 			l*=2;
 		}
 		if(y==0 && w ==W){
 			w = Integer.MAX_VALUE;
 		}else if(y==0 || y+w==W){
 			w*=2;
 		}
 		
 		return min(l,w);
 	}
 	
 	int placeX(int r){
 		if(x==0){
 			return 0;
 		}
 		return x+r;
 	}
 	int placeY(int r){
 		if(y==0){
 			return 0;
 		}
 		return y+r;
 	}
 	@Override
 	public int compareTo(matt arg0) {
 		long arr1 = 1L*w*l;
 		long arr2 = 1L*arg0.w*arg0.l;
 		if(arr1<arr2)return -1;
 		if(arr1>arr2)return 1;
 		return 0;
 	}
 }
 
 class h implements Comparable<h>{
 	int r;int x;int y;
 	int ind;
 	public h(int r,int ind){this.r=r;this.ind=ind;};
 	@Override
 	public int compareTo(h o) {
 		return o.r -r;
 	}
 	
 }
 public class B {
 
 	Scanner scan;
 	InputStream in;
 	
 	int intLine(){
 		return parseInt(scan.nextLine());
 	}
 	
 	String solve(){
 		String res="";
 	    int n = scan.nextInt();
 	    int W = scan.nextInt();
 	    int L = scan.nextInt();
 	    matt.W=W;matt.L=L;
 	    TreeSet<matt>M = new TreeSet<matt>();
 	    M.add(new matt(W,L,0,0));
 	    h[]H = new h[n];
 	    for(int i=0;i<n;i++){
 	    	H[i]=new h(scan.nextInt(),i);
 	    }
 	    sort(H);
 	    for(int i=0;i<n;i++) {
 	    	h p = H[i];
 	    	int r = p.r;
 	    	boolean placed=false;
 	    	for(matt m:M){
 	    		if(m.getM()>=2*p.r){
 	    			 p.x = m.placeX(r);
 	    			 p.y = m.placeY(r);
 	    			 M.remove(m);
 	    			 int cornerX=p.x+r;
 	    			 int cornerY=p.y+r;
 	    			 int l = p.x+r-m.x;
 	    			 int w = p.y+r -m.y;
 	    			 matt bot = new matt(m.y+m.w-cornerY,cornerX-m.x, m.x, cornerY);
 	    			 M.add(bot);
 	    			 matt left = new matt(m.w,m.x+m.l-cornerX, cornerX, m.y);
 	    			 M.add(left);
 	    			 placed = true;
 	    			 break;
 	    		}
 	    	}
 	    	if(!placed)throw new RuntimeException("not placed");
 	    }
 	    String[]r = new String[n];
 	    for(h x:H){
 	    	r[x.ind]=x.y+" "+x.x;
 	    }
 	    for(String s:r)res+=" "+s;
 		return res;
 	}
 	
 	void solveAll(){
 		int N = parseInt(scan.nextLine());
 		for(int i=0;i<N;i++){
 			String r =solve();
 			System.out.format("Case #%d:%s\n",i+1,r);
 		}
 	}
 	
 	B() throws Exception{
 		String cn = B.class.getName();
 		String sampleName = cn+"-sample.in";
 		String smallName = cn+"-small-attempt0.in";
 		String largeName = cn+"-large.in";
 		InputStream in = new BufferedInputStream(new FileInputStream(smallName));
 		scan = new Scanner(in);
 	}
 	
 	public static void main(String[] args) throws Exception{
 	    Locale.setDefault(Locale.US); 
 	    new B().solveAll();
 	}
 
 }
