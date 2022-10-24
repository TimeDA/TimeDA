/* 2017.6.10 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 std::vector<int> pre[10];
 std::map<int, int> nexter[10];
 
 int fact[10];
 int c[20];
 char line[20];
 
 void add(int maxl, int cur, int num, bool first)
 {
 	if (first && nexter[maxl][cur] == cur)
 		num--;
 	pre[maxl][cur] += num;
 	if (nexter[maxl].find(cur) != nexter[maxl].end())
 	{
 		if(nexter[maxl][cur] != cur)
 			add(maxl, nexter[maxl][cur], first ? pre[maxl][cur] : num, false);
 	}
 }
 void calc(int maxl, int cur, int factor)
 {
 	int next = 0;
 	for (int j = 1; j <= maxl; j++)
 		next = next * 10 + c[j];
 	nexter[maxl][cur] = next;
 
 	add(maxl, cur, fact[maxl] / factor, true);
 }
 
 void prego(int level, int maxl, int cur, int rem, int factor)
 {
 	if (level == maxl)
 		calc(maxl, cur, factor * fact[rem]);
 	else
 	{
 		for (int i = 0; i <= maxl; i++)
 		{
 			if (i > rem) break;
 			c[i]++;
 			prego(level + 1, maxl, cur * 10 + i, rem - i, factor * fact[i]);
 			c[i]--;
 		}
 	}
 }
 
 void precalc()
 {
 	for (int a = 1; a <= 9; a++)
 	{
 		int start = a;
 		for (int i = 1; i < a; i++)
 			start = start * 10 + a;
 		pre[a] = std::vector<int>(start + 1);
 
 		prego(0, a, 0, a, 1);
 	}
 }
 
 int main()
 {
 	fact[0] = 1;
 	for (int i = 1; i <= 9; i++)
 		fact[i] = fact[i - 1] * i;
 
 	precalc();
 	int T;
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		fscanf(fin, "%s", line);
 		int G = strlen(line);
 		int l = atoi(line);
 		fprintf(fout, "Case #%d: %d\n", c_n, pre[G][l] + 1);
 		printf("Case #%d: %d\n", c_n, pre[G][l] + 1);
 	}
 	return -0;
 }
