/* 2015.5.30-31 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 #include <iostream>
 
 bool compare(std::pair<double, double> p1, std::pair<double, double> p2)
 {
 	return p1.second < p2.second;
 }
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N;
 		double V, X;
 		fscanf(fin, "%d%lf%lf", &N, &V, &X);
 
 		double rc1 = 0, rc2 = 0;
 		double r1 = 0, r2 = 0, r3 = 0;
 
 		std::vector<std::pair<double, double>> lt;
 		std::vector<std::pair<double, double>> gt;
 		for (int i = 0; i < N; i++)
 		{
 			double r, c;
 			fscanf(fin, "%lf%lf", &r, &c);
 
 			if (c > X)
 				gt.push_back(std::make_pair(r, c - X));
 			else if (c < X)
 				lt.push_back(std::make_pair(r, X - c));
 			else
 				r3 += r;
 		}
 		std::sort(gt.begin(), gt.end(), compare);
 		std::sort(lt.begin(), lt.end(), compare);
 
 		for (auto a : gt)
 		{
 			rc1 += a.first * a.second;
 			r1 += a.first;
 		}
 		for (auto a : lt)
 		{
 			rc2 += a.first * a.second;
 			r2 += a.first;
 		}
 
 		if (r3 == 0 && (gt.size() == 0 || lt.size() == 0))
 		{
 			fprintf(fout, "Case #%d: IMPOSSIBLE\n", c_n);
 			printf("Case #%d: IMPOSSIBLE\n", c_n);
 			continue;
 		}
 		std::vector<std::pair<double, double>>& st = (rc1 > rc2 ? gt : lt);
 		double rc = std::min(rc1, rc2);
 		double r = (rc1 > rc2 ? r2 : r1) + r3;
 
 		for (auto a : st)
 		{
 			if (a.first * a.second > rc)
 			{
 				r += rc / a.second;
 				break;
 			}
 			else
 			{
 				r += a.first;
 				rc -= a.first * a.second;
 			}
 		}
 
 		double result = V / r;
 		fprintf(fout, "Case #%d: %.10f\n", c_n, result);
 		printf("Case #%d: %.10f\n", c_n, result);
 	}
 	return -0;
 }
