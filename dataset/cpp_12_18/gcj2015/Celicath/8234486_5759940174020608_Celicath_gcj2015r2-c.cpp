/* 2015.5.31 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 #include <iostream>
 
 char line[15000];
 char word[1500];
 int lang[1500];
 int language[1500];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	lang[0] = 1;
 	lang[1] = 2;
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N;
 		fscanf(fin, "%d\n", &N);
 
 		std::multimap<int, int> sentence;
 		std::map<std::string, int> dict;
 
 		int count = 0;
 
 		for (int i = 0; i < N; i++)
 		{
 			fgets(line, 14999, fin);
 			int offset = 0;
 			while (true)
 			{
 				int r = sscanf(line + offset, "%s", word);
 				if (r == -1)
 					break;
 				std::string s = word;
 				offset += s.size() + 1;
 				auto a = dict.find(s);
 				if (a == dict.end())
 				{
 					sentence.insert(std::make_pair(i, count));
 					dict[s] = count++;
 				}
 				else sentence.insert(std::make_pair(i, a->second));
 			}
 		}
 
 		for (int i = 2; i < N; i++)
 		{
 			lang[i] = 1;
 		}
 
 		int result = std::numeric_limits<int>().max();
 
 		for (;;)
 		{
 			// 0 : ?, 1 : english, 2 : french, 3 : both
 			for (int i = 0; i < count; i++)
 				language[i] = 0;
 
 			for (int i = 0; i < N; i++)
 			{
 				auto p = sentence.equal_range(i);
 				for (auto it = p.first; it != p.second; it++)
 				{
 					language[it->second] |= lang[i];
 				}
 			}
 			int sresult = 0;
 			for (int i = 0; i < count; i++)
 			{
 				if (language[i] == 3)
 					sresult++;
 			}
 			if (sresult < result)
 				result = sresult;
 
 			for (int i = 2; i <= N; i++)
 			{
 				if (i == N)
 					goto hell;
 				lang[i] = 3 - lang[i];
 				if (lang[i] == 2)
 					break;
 			}
 		}
 	hell:
 		fprintf(fout, "Case #%d: %d\n", c_n, result);
 		printf("Case #%d: %d\n", c_n, result);
 	}
 	return -0;
 }
