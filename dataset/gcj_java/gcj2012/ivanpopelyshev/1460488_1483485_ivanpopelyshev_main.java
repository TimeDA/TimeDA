import java.io.*;
 
 import java.awt.geom.Point2D;
 import java.text.*;
 import java.math.*;
 import java.util.*;
 
 public class Main implements Runnable {
 
 	final String filename = "A-small-attempt0";
 
 	public void solve() throws Exception {
 //		int[] map = new int[26];
 //		Arrays.fill(map, -1);
 //		while (true) {
 //			String s = in.readLine();
 //			String t = in.readLine();
 //			for (int i = 0; i < s.length(); i++) {
 //				if (s.charAt(i) == ' ')
 //					continue;
 //				map[s.charAt(i) - 'a'] = t.charAt(i) - 'a';
 //			}
 //			int count = 0;
 //			int a = -1, b = 0;
 //			for (int i = 0; i < 26; i++)
 //				if (map[i]==-1)
 //				{
 //					a = i;
 //					count++;
 //				}
 //				else b+=map[i];
 //			for (int i=0; i<26; i++)
 //				b-=i;
 //			b=-b;
 //			if (count==1)
 //				map[a] = b;
 //			
 //			for (int i = 0; i < 26; i++)
 //				if (map[i] == -1)
 //					System.out.print("#");
 //				else
 //					System.out.print((char) (map[i] + 'a'));
 //			System.out.println();
 //		}
 		String map = "yhesocvxduiglbkrztnwjpfmaq";
 		int ntest = Integer.parseInt(in.readLine());
 		for (int test=1;test<=ntest;test++)
 		{
 			String s = in.readLine();
 			StringBuilder t = new StringBuilder();
 			for (int i=0; i<s.length(); i++)
 				if (s.charAt(i)==' ')
 					t.append(' ');
 				else t.append(map.charAt(s.charAt(i)-'a'));
 			out.write("Case #"+test+": "+t.toString()+"\n");
 		}
 	}
 
 	public void run() {
 		try {
 //			in = new BufferedReader(new InputStreamReader(System.in));
 //			out = new BufferedWriter(new OutputStreamWriter(System.out));
 			 in = new BufferedReader(new FileReader(filename+".in"));
 			 out = new BufferedWriter(new FileWriter(filename+".out"));
 			solve();
 			out.flush();
 		} catch (Exception e) {
 			e.printStackTrace();
 			System.exit(1);
 		}
 	}
 
 	public int iread() throws Exception {
 		return Integer.parseInt(readword());
 	}
 
 	public double dread() throws Exception {
 		return Double.parseDouble(readword());
 	}
 
 	public long lread() throws Exception {
 		return Long.parseLong(readword());
 	}
 
 	BufferedReader in;
 
 	BufferedWriter out;
 
 	public String readword() throws IOException {
 		StringBuilder b = new StringBuilder();
 		int c;
 		c = in.read();
 		while (c >= 0 && c <= ' ')
 			c = in.read();
 		if (c < 0)
 			return "";
 		while (c > ' ') {
 			b.append((char) c);
 			c = in.read();
 		}
 		return b.toString();
 	}
 
 	public static void main(String[] args) {
 		try {
 			Locale.setDefault(Locale.US);
 		} catch (Exception e) {
 
 		}
 		// new Thread(new Main()).start();
 		new Thread(null, new Main(), "1", 1 << 25).start();
 	}
 }