package qr2012;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.util.HashMap;
 
 public class SpeakingInTongues {
 	HashMap<Character, Character> map = new HashMap<Character, Character>();
 
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		SpeakingInTongues obj = new SpeakingInTongues();
 		obj.solve(fileName);
 	}
 
 	public void solve(String fileName) throws Exception {
 		String[][] hints = {
 				{ "y qee", "a zoo" },
 				{ "ejp mysljylc kd kxveddknmc re jsicpdrysi",
 						"our language is impossible to understand" },
 				{ "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
 						"there are twenty six factorial possibilities" },
 				{ "de kr kd eoya kw aej tysr re ujdr lkgc jv",
 						"so it is okay if you want to just give up" },
 				{ "z", "q" } };
 
 		for (String[] tmp : hints) {
 			for (int i = 0; i < tmp[0].length(); i++) {
 				if (tmp[0].charAt(i) != ' ') {
 					map.put(tmp[0].charAt(i), tmp[1].charAt(i));
 				}
 			}
 		}
 
 		BufferedReader br = new BufferedReader(new FileReader(fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(fileName + ".out"));
 
 		int T = Integer.parseInt(br.readLine());
 		for (int i = 0; i < T; i++) {
 			String str = br.readLine();
 
 			StringBuffer buf = new StringBuffer();
 			for (int j = 0; j < str.length(); j++) {
 				if (str.charAt(j) == ' ') {
 					buf.append(' ');
 				} else {
 					buf.append(map.get(str.charAt(j)));
 				}
 			}
 
 			bw.write("Case #" + (i + 1) + ": ");
 			bw.write("" + buf.toString());
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
