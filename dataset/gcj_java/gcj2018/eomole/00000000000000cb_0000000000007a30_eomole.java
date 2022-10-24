import java.util.Scanner;

class GoGopher {
    static void interact(Scanner sc) {
        final int A = sc.nextInt();
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                int cnt = 0;
                final boolean[][] map = new boolean[3][3];
                while (cnt < 9) {
                    System.out.printf("%d %d\n", i * 3 + 2, j * 3 + 2);
                    System.out.flush();
                    final int x = sc.nextInt();
                    final int y = sc.nextInt();
                    if (x == 0 && y == 0)
                        return;
                    final int xx = (x - 1) % 3;
                    final int yy = (y - 1) % 3;
                    if (!map[xx][yy]) {
                        cnt++;
                        map[xx][yy] = true;
                    }
                }
            }
    }

    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int c = 1; c <= T; c++)
            interact(sc);
    }
}
public class Solution {
    public static void main(String...args) {
        GoGopher.main();
    }
}
