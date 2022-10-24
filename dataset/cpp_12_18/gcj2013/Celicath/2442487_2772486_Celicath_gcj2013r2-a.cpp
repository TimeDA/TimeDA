/* 2013.6.1 Yoshi-TS4 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <limits>
 #include <algorithm>
 #include <vector>
 #include <map>
 
 int o[2000], e[2000], p[2000];
 int N, M;
 std::map<int, long long> points;
 
 long long cost(long long n)
 {
 	return n * (long long)N - n * (n-1) / 2;
 }
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 	long long all;
 	long long all2;
 
 	fscanf(fin, "%d", &T);
 
 	for(int a = 1; a <= T; a++)
 	{
 		points.clear();
 		all = all2 = 0;
 		fscanf(fin, "%d%d", &N, &M);
 		for(int i = 0; i < M; i++)
 		{
 			fscanf(fin, "%d%d%d", o+i, e+i, p+i);
 			points[o[i]] += p[i];
 			points[e[i]] -= p[i];
 			all = (all + cost(e[i] - o[i]) * p[i]) % 1000002013;
 		}
 
 		for (auto p1 = points.rbegin(); p1 != points.rend(); p1++)
 		{
 			if(p1->second > 0)
 			{
 				for (auto p2 = p1.base(); p2 != points.end(); p2++)
 				{
 					if(p2->second < 0)
 					{
 						long long down = std::min(p1->second, -p2->second);
 						p1->second -= down;
 						p2->second += down;
 						all2 = (all2 + cost(p2->first - p1->first) * down) % 1000002013;
 						if(p1->second == 0) break;
 						else if(p1->second < 0)
 							printf("ASDF\n");
 					}
 				}
 			}
 		}
 		long long result = all - all2;
 		if(result < 0) result += 1000002013;
 		fprintf(fout, "Case #%d: %lld\n", a, result);
 	}
 
 	return -0;
 }
