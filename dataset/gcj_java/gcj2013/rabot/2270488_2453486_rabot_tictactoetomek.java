package qr2013;
 
 import java.io.BufferedReader;
 import java.io.BufferedWriter;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.StringTokenizer;
 
 public class TicTacToeTomek {
 	public static void main(String[] args) throws Exception {
 		String fileName = args[0];
 		TicTacToeTomek obj = new TicTacToeTomek();
 		obj.solve(fileName);
 	}
 
 	public void solve(String fileName) throws Exception {
 		int SIZE = 4;
 
 		BufferedReader br = new BufferedReader(new FileReader(fileName));
 		BufferedWriter bw = new BufferedWriter(
 				new FileWriter(fileName + ".out"));
 
 		int T = Integer.parseInt(br.readLine());
 		for (int i = 0; i < T; i++) {
 			String[] board = new String[4];
 			for (int j = 0 ; j < SIZE ; j++ ) {
 				board[j] = br.readLine();
 			}
 			br.readLine();
 
 			boolean empty = false;
 			boolean Xwon = true;
 			boolean Owon = true;
 			for (int x = 0; x < SIZE; x++) {
 				Xwon = true;
 				Owon = true;
 				for (int y = 0 ; y < SIZE ; y++) {
 					char c = board[x].charAt(y);
 					if ( c == 'X' ) {
 						Owon = false;
 					} else if ( c == 'O' ) {
 						Xwon = false;
 					} else if ( c == '.' ) {
 						Xwon = false;
 						Owon = false;
 						empty = true;
 						break;
 					}
 				}
 				if (Xwon || Owon) {
 					break;
 				}
 			}
 
 			if ( !(Xwon || Owon) ) {
 				for (int y = 0; y < SIZE; y++) {
 					Xwon = true;
 					Owon = true;
 					for (int x = 0 ; x < SIZE ; x++) {
 						char c = board[x].charAt(y);
 						if ( c == 'X' ) {
 							Owon = false;
 						} else if ( c == 'O' ) {
 							Xwon = false;
 						} else if ( c == '.' ) {
 							Xwon = false;
 							Owon = false;
 							break;
 						}
 					}
 					if (Xwon || Owon) {
 						break;
 					}
 				}
 			}
 
 			if ( !(Xwon || Owon) ) {
 				Xwon = true;
 				Owon = true;
 				for (int x = 0 ; x < SIZE ; x++) {
 					char c = board[x].charAt(x);
 					if ( c == 'X' ) {
 						Owon = false;
 					} else if ( c == 'O' ) {
 						Xwon = false;
 					} else if ( c == '.' ) {
 						Xwon = false;
 						Owon = false;
 						break;
 					}
 				}
 			}
 
 			if ( !(Xwon || Owon) ) {
 				Xwon = true;
 				Owon = true;
 				for (int x = 0 ; x < SIZE ; x++) {
 					char c = board[x].charAt(SIZE-1-x);
 					if ( c == 'X' ) {
 						Owon = false;
 					} else if ( c == 'O' ) {
 						Xwon = false;
 					} else if ( c == '.' ) {
 						Xwon = false;
 						Owon = false;
 						break;
 					}
 				}
 			}
 
 			bw.write("Case #" + (i + 1) + ": ");
 			if (Xwon) {
 				bw.write("X won");
 			} else if (Owon) {
 				bw.write("O won");
 			} else if (empty) {
 				bw.write("Game has not completed");
 			} else {
 				bw.write("Draw");
 			}
 			bw.write("\r\n");
 		}
 		bw.close();
 		br.close();
 	}
 }
 
 class Student implements Comparable<Student> {
 	Long r = 0L;
 	Integer idx = 0;
 	long x = 0;
 	long y = 0;
 
 	Student(long r, int idx) {
 		this.r = r;
 		this.idx = idx;
 	}
 
 	@Override
 	public int compareTo(Student o) {
 		int tmp = this.r.compareTo(o.r);
 
 		return tmp == 0 ? this.idx.compareTo(o.idx) : -tmp;
 	}
 }
 
 class Point {
 	long x = 0;
 	long y = 0;
 
 	Point(long x, long y) {
 		this.x = x;
 		this.y = y;
 	}
 }
