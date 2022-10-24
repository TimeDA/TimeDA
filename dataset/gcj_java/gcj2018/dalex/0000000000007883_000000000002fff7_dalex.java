import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution {
    private BufferedReader in;
    private StringTokenizer tok;
    private PrintWriter out;

    //------------------------------------------------------------------------------
    public static void main(String[] args) {
        new Solution().run();
    }

    private void solve() throws IOException {
        int T = readInt();
        for (int t = 1; t <= T; t++) {
            solveTest(t);
        }
    }

    private static final double EPS = 1e-12;

    private static class Cookie {
        int x, y;

        private Cookie(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static class Segment {
        double L, R;

        private Segment(double l, double r) {
            L = l;
            R = r;
        }

        @Override
        public String toString() {
            return String.format(Locale.US, "[%.6f %.6f]", L, R);
        }
    }

    private void solveTest(int t) throws IOException {
        out.printf("Case #%d: ", t);
        int n = readInt();
        int P = readInt();
        Cookie[] cookies = new Cookie[n];
        for (int i = 0; i < n; i++) {
            cookies[i] = new Cookie(readInt(), readInt());
        }
        int have = 0;
        for (int i = 0; i < n; i++) {
            have += 2 * (cookies[i].x + cookies[i].y);
        }
        if (have > P) {
            throw new AssertionError();
        }
        final double rem = P - have;
        List<Segment> list = new ArrayList<>();
        list.add(new Segment(0.0, 0.0));
        for (int i = 0; i < n; i++) {
            int x = cookies[i].x;
            int y = cookies[i].y;
            double mn = 2.0 * Math.min(x, y);
            double mx = 2.0 * Math.sqrt(x * x + y * y);
            List<Segment> addedList = new ArrayList<>();
            for (Segment s : list) {
                addedList.add(new Segment(s.L + mn, s.R + mx));
            }
            //noinspection UnnecessaryLocalVariable
            List<Segment> newList = merge(list, addedList);
            list = newList;
        }
        double ans = 0.0;
        for (Segment s : list) {
            if (s.L - EPS < rem) {
                ans = Math.max(ans, Math.min(rem, s.R));
            }
        }
        out.printf(Locale.US, "%.15f\n", have + ans);
    }

    private static class Event implements Comparable<Event> {
        private static final int OPEN = 0;
        private static final int CLOSE = 1;

        double coord;
        int type;

        private Event(double coord, int type) {
            this.coord = coord;
            this.type = type;
        }

        @Override
        public int compareTo(Event o) {
            if (Math.abs(coord - o.coord) < EPS) {
                return Integer.compare(type, o.type);
            }
            return Double.compare(coord, o.coord);
        }
    }

    private List<Segment> merge(List<Segment> a, List<Segment> b) {
        List<Event> events = new ArrayList<>();
        for (Segment s : a) {
            events.add(new Event(s.L, Event.OPEN));
            events.add(new Event(s.R, Event.CLOSE));
        }
        for (Segment s : b) {
            events.add(new Event(s.L, Event.OPEN));
            events.add(new Event(s.R, Event.CLOSE));
        }
        Collections.sort(events);
        List<Segment> ans = new ArrayList<>();
        int cnt = 0;
        double start = -1.0;
        for (Event e : events) {
            if (e.type == Event.OPEN) {
                cnt++;
                if (start == -1.0) {
                    start = e.coord;
                }
            } else {
                cnt--;
                if (cnt == 0) {
                    ans.add(new Segment(start, e.coord));
                    start = -1.0;
                }
            }
        }
        return ans;
    }

    private void run() {
        try {
            initIO();
            solve();
            in.close();
            out.close();
        } catch (Throwable e) {
            throw new RuntimeException(e);
        }
    }

    private void initIO() throws IOException {
        if (new File("input.txt").exists()) {
            in = new BufferedReader(new FileReader(new File("input.txt")));
            out = new PrintWriter(new File("output.txt"));
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
    }

    private String readString() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    @SuppressWarnings("unused")
    private int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    @SuppressWarnings("unused")
    private long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    @SuppressWarnings("unused")
    private double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
}
