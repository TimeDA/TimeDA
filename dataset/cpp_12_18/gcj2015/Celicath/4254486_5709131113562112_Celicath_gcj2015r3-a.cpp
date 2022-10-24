/* 2015.6.14 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 int S[100005];
 int M[100005];
 
 bool mang[100005];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N, D;
 		fscanf(fin, "%d%d\n", &N, &D);
 		int S0, As, Cs, Rs;
 		fscanf(fin, "%d%d%d%d\n", &S0, &As, &Cs, &Rs);
 		int M0, Am, Cm, Rm;
 		fscanf(fin, "%d%d%d%d\n", &M0, &Am, &Cm, &Rm);
 
 		S[0] = S0; M[0] = M0;
 
 		std::set<int> ss;
 		ss.insert(S0);
 
 		for (int i = 1; i < N; i++)
 		{
 			S[i] = S0 = (S0 * As + Cs) % Rs;
 			if (S[i] < S[0] && S[i] >= S[0] - D)
 				ss.insert(S[i]);
 			else if (S[i] > S[0] && S[i] <= S[0] + D)
 				ss.insert(S[i] - D);
 			M0 = (M0 * Am + Cm) % Rm;
 			M[i] = (M0 % i);
 		}
 
 		int result = 0;
 
 		mang[0] = false;
 		for (int n : ss)
 		{
 			int cur = 1;
 			for (int i = 1; i < N; i++)
 			{
 				if (!mang[M[i]] && S[i] >= n && S[i] <= n + D)
 				{
 					mang[i] = false;
 					cur++;
 				}
 				else mang[i] = true;
 			}
 			if (result < cur)
 				result = cur;
 		}
 
 		fprintf(fout, "Case #%d: %d\n", c_n, result);
 		printf("Case #%d: %d\n", c_n, result);
 	}
 	return -0;
 }
