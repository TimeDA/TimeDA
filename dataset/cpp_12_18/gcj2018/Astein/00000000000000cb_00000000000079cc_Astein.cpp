#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void solve_2d(double A)
{
	double min_angle = 0, max_angle = 3.1415926535 / 4.0;
	for (int step = 0; step < 100; ++step)
	{
		double avg_angle = (min_angle + max_angle) / 2.0;
		double cur_area = cos(avg_angle) + sin(avg_angle);
		if (cur_area < A)
		{
			min_angle = avg_angle;
		}
		else
		{
			max_angle = avg_angle;
		}
	}

	printf("%.12lf %.12lf 0\n", 0.5 * cos(min_angle), 0.5 * sin(min_angle));
	printf("%.12lf %.12lf 0\n", -0.5 * sin(min_angle), 0.5 * cos(min_angle));
	printf("0 0 0.5\n");
}

struct Point3D
{
	double x, y, z;

	Point3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

double area_2d(const vector<Point3D>& points, vector<int> indexes)
{
	double area = 0;
	for (int i = 0; i < indexes.size(); ++i)
	{
		area += points[indexes[i]].x * points[indexes[(i + 1) % indexes.size()]].z;
		area -= points[indexes[i]].z * points[indexes[(i + 1) % indexes.size()]].x;
	}
	return abs(area) / 2.0;
}

void solve_3d(double A)
{
	double sqrt2h = sqrt(2.0) / 2.0;
	vector<Point3D> points = {
		{ sqrt2h , 0, 0.5 }, { sqrt2h, 0, -0.5 },
		{ 0, -sqrt2h , 0.5 }, { 0, -sqrt2h, -0.5 },
		{ 0, sqrt2h , 0.5 }, { 0, sqrt2h, -0.5 },
		{ -sqrt2h , 0, 0.5 }, { -sqrt2h, 0, -0.5 },
	};
	double min_angle = 0;
	double max_angle = 35.264390353495287;

	for (int step = 0; step < 100; ++step)
	{
		auto get_area = [points](double angle) {
			vector<Point3D> conv_points;
			for (int i = 0; i < 8; ++i)
			{
				Point3D point = { points[i].x, cos(angle) * points[i].y - sin(angle) * points[i].z, sin(angle) * points[i].y + cos(angle) * points[i].z };
				conv_points.push_back(point);
			}
			double cur_area = area_2d(conv_points, { 0, 1, 5, 4 });
			cur_area += area_2d(conv_points, { 4, 5, 7, 6 });
			cur_area += area_2d(conv_points, { 0, 4, 6, 2 });

			return cur_area;
		};

		double avg_angle = (min_angle + max_angle) / 2.0;
		double cur_area = get_area(avg_angle);
		if (cur_area < A)
		{
			min_angle = avg_angle;
		}
		else
		{
			max_angle = avg_angle;
		}
	}

	double angle = min_angle;
	vector<Point3D> conv_points;
	for (int i = 0; i < 8; ++i)
	{
		Point3D point = { points[i].x, cos(angle) * points[i].y - sin(angle) * points[i].z, sin(angle) * points[i].y + cos(angle) * points[i].z };
		conv_points.push_back(point);
	}

	auto print_center = [conv_points](vector<int> indexes) {
		double x = 0, y = 0, z = 0;
		for (int i = 0; i < indexes.size(); ++i)
		{
			x += conv_points[indexes[i]].x;
			y += conv_points[indexes[i]].y;
			z += conv_points[indexes[i]].z;
		}
		x /= indexes.size();
		y /= indexes.size();
		z /= indexes.size();
		printf("%.12lf %.12lf %.12lf\n", x, y, z);
	};

	print_center({ 0, 1, 5, 4 });
	print_center({ 4, 5, 7, 6 });
	print_center({ 0, 4, 6, 2 });
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		printf("Case #%d:\n", cn);
		double A;
		scanf("%lf", &A);
		if (A < 1.414214)
		{
			solve_2d(A);
		}
		else
		{
			solve_3d(A);
		}
	}
}