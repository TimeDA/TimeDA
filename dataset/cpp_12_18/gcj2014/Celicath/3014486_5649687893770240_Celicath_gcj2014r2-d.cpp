/* 2014.6.1 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 #include <iostream>
 
 std::string str[2000];
 std::multimap<std::string, std::string> map;
 std::set<std::string> set[2000];
 
 int pos[2000];
 
 int M, N;
 int max, maxc;
 
 void go(int level)
 {
 	if (level == M)
 	{
 		int tot = 0;
 		for (int i = 0; i < N; i++)
 		{
 			set[i].clear();
 		}
 		for (int i = 0; i < M; i++)
 		{
 			auto p = map.equal_range(str[i]);
 			for (auto a = p.first; a != p.second; a++)
 			{
 				set[pos[i]].insert((*a).second);
 			}
 		}
 		for (int i = 0; i < N; i++)
 			tot += set[i].size();
 		if (tot > max)
 		{
 			max = tot;
 			maxc = 1;
 		}
 		else if (tot == max)
 			maxc++;
 	}
 	else
 	{
 		for (int i = 0; i < N; i++)
 		{
 			pos[level] = i;
 			go(level + 1);
 		}
 	}
 }
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		max = 0, maxc = 0;
 		fscanf(fin, "%d%d", &M, &N);
 
 		map.clear();
 		for (int i = 0; i < M; i++)
 		{
 			char temp[2000];
 			fscanf(fin, "%s", temp);
 			str[i] = temp;
 			for (int j = 0; j <= str[i].size(); j++)
 				map.insert(std::make_pair(str[i], str[i].substr(0, j)));
 		}
 
 		go(0);
 
 		fprintf(fout, "Case #%d: %d %d\n", c_n, max, maxc);
 		printf("Case #%d: %d %d\n", c_n, max, maxc);
 	}
 	return -0;
 }
