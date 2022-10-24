import java.util.Scanner;

public class Solution {
	static final double TOLERANCE = 1e-9;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			double A = sc.nextDouble();

			Point[] points = solve(A);
			System.out.println("Case #" + tc + ":");
			for (Point point : points) {
				System.out.println(point.x + " " + point.y + " " + point.z);
			}
		}

		sc.close();
	}

	static Point[] solve(double A) {
		Point centerUp = new Point(0, 0.5, 0);
		Point centerFrontRight = new Point(Math.sqrt(2) / 4, 0, Math.sqrt(2) / 4);
		Point centerFrontLeft = new Point(-Math.sqrt(2) / 4, 0, Math.sqrt(2) / 4);

		double lowerAngle = 0;
		double upperAngle = Math.atan(Math.sqrt(2));
		while (true) {
			double middleAngle = (lowerAngle + upperAngle) / 2;

			Point rotatedCenterUp = rotateAboutZ(centerUp, middleAngle);
			Point rotatedCenterFrontRight = rotateAboutZ(centerFrontRight, middleAngle);
			Point rotatedCenterFrontLeft = rotateAboutZ(centerFrontLeft, middleAngle);

			Point[] vertices = {
					new Point().subtract(rotatedCenterUp).add(rotatedCenterFrontRight).subtract(rotatedCenterFrontLeft),
					new Point().subtract(rotatedCenterUp).add(rotatedCenterFrontRight).add(rotatedCenterFrontLeft),
					new Point().add(rotatedCenterUp).add(rotatedCenterFrontRight).add(rotatedCenterFrontLeft),
					new Point().add(rotatedCenterUp).subtract(rotatedCenterFrontRight).add(rotatedCenterFrontLeft),
					new Point().add(rotatedCenterUp).subtract(rotatedCenterFrontRight).subtract(rotatedCenterFrontLeft),
					new Point().subtract(rotatedCenterUp).subtract(rotatedCenterFrontRight)
							.subtract(rotatedCenterFrontLeft) };
			double area = computeArea(vertices);

			if (Math.abs(area - A) < TOLERANCE) {
				return new Point[] { rotatedCenterUp, rotatedCenterFrontRight, rotatedCenterFrontLeft };
			} else if (area < A) {
				lowerAngle = middleAngle;
			} else {
				upperAngle = middleAngle;
			}
		}
	}

	static Point rotateAboutZ(Point p, double angle) {
		return new Point(p.x * Math.cos(angle) - p.y * Math.sin(angle), p.x * Math.sin(angle) + p.y * Math.cos(angle),
				p.z);
	}

	static double computeArea(Point[] vertices) {
		double area = 0;
		for (int i = 1; i + 1 < vertices.length; i++) {
			double x1 = vertices[i].x - vertices[0].x;
			double z1 = vertices[i].z - vertices[0].z;
			double x2 = vertices[i + 1].x - vertices[0].x;
			double z2 = vertices[i + 1].z - vertices[0].z;

			double cross = x1 * z2 - x2 * z1;
			area += cross;
		}
		area = Math.abs(area / 2);
		return area;
	}
}

class Point {
	double x;
	double y;
	double z;

	Point() {
		this(0, 0, 0);
	}

	Point(double x, double y, double z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	Point add(Point other) {
		return new Point(x + other.x, y + other.y, z + other.z);
	}

	Point subtract(Point other) {
		return add(new Point(-other.x, -other.y, -other.z));
	}
}