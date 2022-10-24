import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 
 
 public class ProblemA {
 	public static void main(String[] args) throws IOException {
 		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
 		char[] map = new char[512];
 		String from = "abcdefghijklmnopqrstuvwxyz";
 		String to = "yhesocvxduiglbkrztnwjpfmaq";
 		for (int i = 0 ; i < 26 ; i++) {
 			char x = from.charAt(i);
 			char y = to.charAt(i);
 			map[x] = y;
 		}
 		
 		int T = Integer.valueOf(reader.readLine());
 		for (int t = 1 ; t <= T ; t++) {
 			String line = reader.readLine();
 			System.out.println("Case #" + t + ": " + convert(line, map));
 		}
 	}
 
 	private static String convert(String line, char[] map) {
 		int len = line.length();
 		String to = "";
 		for (int i = 0 ; i < len ; i++) {
 			if (line.charAt(i) == ' ') {
 				to += ' ';
 			} else {
 				char c = line.charAt(i);
 				to += map[c];
 			}
 		}
  		return to;
 	}
 }
