
 import java.io.BufferedWriter;
 import java.io.File;
 import java.io.FileWriter;
 import java.util.Scanner;
 
 public class ProblemB {
 	public static void main(String[] args) throws Exception {
 		Scanner sc = new Scanner(System.in);
 		String fileName = sc.next();
 		sc.close();
 		int fileNamePos = fileName.indexOf('.');
 		String outputFileName = null;
 		if (fileNamePos >= 0) {
 			outputFileName = fileName.substring(0, fileNamePos) + ".out.txt";
 		} else {
 			outputFileName = fileName + ".out.txt";
 		}
 
 		String path = ProblemB.class.getResource("").getPath();
 		path = path.substring(0, path.lastIndexOf('/'));
 		path = path.substring(0, path.lastIndexOf('/')) + "/src/";
 
 		sc = new Scanner(new File(path + fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(path + outputFileName));
 
 		int T = sc.nextInt();
 		for (int i = 1; i <= T; i++) {
 			String N = sc.next();
 
 			int[] NN = new int[N.length()];
 			for (int j = 0; j < N.length(); j++) {
 				NN[j] = N.charAt(j) - '0';
 			}
 			for (int j = NN.length - 1; j >= 1; j--) {
 				if (NN[j - 1] > NN[j]) {
 					NN[j - 1] = NN[j - 1] - 1;
 					for (int k = j; k < NN.length; k++) {
 						NN[k] = 9;
 					}
 				}
 			}
 			StringBuffer buf = new StringBuffer();
 			for (int j = 0; j < NN.length; j++) {
 				if (buf.length() > 0 || NN[j] != 0) {
 					buf.append(NN[j]);
 				}
 			}
 			bw.write("Case #" + i + ": " + buf.toString());
 			bw.write("\r\n");
 		}
 		bw.close();
 		sc.close();
 	}
 }
