import java.awt.geom.Point2D;
import java.util.Locale;
import java.util.Scanner;

public class Solution {
    static double SQRT2 = Math.sqrt(2);

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t=1; t<=T; t++) {
            double A = in.nextDouble();
            double alpha = findAlpha(A);
            Point2D.Double top = rotate(new Point2D.Double(0, 0.5), alpha);
            Point2D.Double left = rotate(new Point2D.Double(-SQRT2/4, 0), alpha);
            Point2D.Double right = rotate(new Point2D.Double(SQRT2/4, 0), alpha);
            System.out.printf("Case #%d:\n", t);
            System.out.printf("%.10f %.10f %.10f\n", top.x, top.y, 0.0);
            System.out.printf("%.10f %.10f %.10f\n", left.x, left.y, SQRT2/4);
            System.out.printf("%.10f %.10f %.10f\n", right.x, right.y, SQRT2/4);
        }
    }

    static double findAlpha(double area) {
        double min = 0;
        double max = Math.PI/2-Math.atan(1/SQRT2);
        while (max - min > 1e-10) {
            double mid = (min + max)/2;
            if (area(mid) > area) {
                max = mid;
            } else {
                min = mid;
            }
        }
        return (min + max)/2;
    }

    static double area(double alpha) {
        Point2D.Double left = rotate(new Point2D.Double(-1/SQRT2, 0.5), alpha);
        Point2D.Double right = rotate(new Point2D.Double(1/SQRT2, -0.5), alpha);
        Point2D.Double topLeft = rotate(new Point2D.Double(0, 0.5), alpha);
        Point2D.Double topRight = rotate(new Point2D.Double(0, -0.5), alpha);
        double center = topRight.x-topLeft.x;
        return SQRT2*(right.x-left.x+center)/2;
    }

    static Point2D.Double rotate(Point2D.Double point, double alpha) {
        double cAlpha = Math.cos(alpha);
        double sAlpha = Math.sin(alpha);
        return new Point2D.Double(point.x*cAlpha - point.y*sAlpha, point.x*sAlpha + point.y*cAlpha);
    } 

}
