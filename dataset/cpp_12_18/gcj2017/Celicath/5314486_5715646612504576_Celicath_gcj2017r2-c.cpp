/* 2017.5.13 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 char map[100][100];
 
 std::vector<int> beams;	// beam position
 std::map<int, std::vector<int>> cell_to_beam;
 std::vector<int> beam_ori;	// beam's possible orientation(bit); 1=hori 2=vert
 
 int graph[500][500];
 
 int R, C;
 
 void AddBeam(int x, int y)
 {
 	beams.push_back(x * 100 + y);
 	beam_ori.push_back(3);
 }
 
 void Go(int beamno, int ori, int x, int y, int dx, int dy)
 {
 	x += dx;
 	y += dy;
 	if (x < 0 || x >= R || y < 0 || y >= C)
 		return;
 	if (map[x][y] == '.')
 	{
 		cell_to_beam[100 * x + y].push_back(beamno + 100 * ori);
 	}
 	else if (map[x][y] == '#')
 		return;
 	else if (map[x][y] == '|' || map[x][y] == '-')
 	{
 		beam_ori[beamno] &= (3 - ori);
 		return;
 	}
 	else if (map[x][y] == '\\')
 	{
 		int temp = dx;
 		dx = dy;
 		dy = temp;
 	}
 	else if (map[x][y] == '/')
 	{
 		int temp = dx;
 		dx = -dy;
 		dy = -temp;
 	}
 	else printf("ERROR : ILLEGAL GRID");
 	Go(beamno, ori, x, y, dx, dy);
 }
 
 bool StartGraph(int beamno, int ori, std::map<int, int>& visited)
 {
 	if (visited.find(beamno) != visited.end())
 	{
 		return ori == visited[beamno];
 	}
 	visited[beamno] = ori;
 	for (int j = 0; j < 2 * beams.size(); j++)
 	{
 		if (graph[beamno + 100 * ori][j / 2 + 100 + 100 * (j % 2)])
 			if (!StartGraph(j / 2, 1 + 1 * (j % 2), visited))
 				return false;
 	}
 	return true;
 }
 
 int main()
 {
 	int T;
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		fscanf(fin, "%d%d", &R, &C);
 		beams.clear();
 		cell_to_beam.clear();
 		beam_ori.clear();
 		for (int i = 0; i < 500; i++)
 			for (int j = 0; j < 500; j++)
 				graph[i][j] = 0;
 
 		for (int i = 0; i < R; i++)
 		{
 			fscanf(fin, "%s", map[i]);
 
 			for (int j = 0; j < C; j++)
 			{
 				if (map[i][j] == '.')
 					cell_to_beam[100 * i + j] = std::vector<int>();
 				else if (map[i][j] == '-' || map[i][j] == '|')
 				{
 					AddBeam(i, j);
 				}
 			}
 		}
 
 		for (int i = 0; i < beams.size(); i++)
 		{
 			Go(i, 1, beams[i] / 100, beams[i] % 100, 0, -1);
 			Go(i, 1, beams[i] / 100, beams[i] % 100, 0, 1);
 			Go(i, 2, beams[i] / 100, beams[i] % 100, -1, 0);
 			Go(i, 2, beams[i] / 100, beams[i] % 100, 1, 0);
 		}
 
 		for (auto it = cell_to_beam.begin(); it != cell_to_beam.end(); it++)
 		{
 			for (auto it2 = it->second.begin(); it2 != it->second.end(); )
 			{
 				int beamno = *it2 % 100;
 				int ori = *it2 / 100;
 				if ((beam_ori[beamno] & ori) == 0)
 				{
 					it2 = it->second.erase(it2);
 				}
 				else it2++;
 			}
 			if (it->second.empty())
 			{
 				goto hell;
 			}
 			else if (it->second.size() == 1)
 			{
 				beam_ori[it->second[0] % 100] = it->second[0] / 100;
 			}
 			else
 			{
 				if (it->second.size() == 2)
 				{
 					int bn1 = it->second[0] % 100;
 					int ori1 = it->second[0] / 100;
 					int bn2 = it->second[1] % 100;
 					int ori2 = it->second[1] / 100;
 
 					graph[bn1 + (3 - ori1) * 100][bn2 + ori2 * 100] = 1;
 					graph[bn2 + (3 - ori2) * 100][bn1 + ori1 * 100] = 1;
 				}
 				else printf("ERROR : N-SAT IS NP-HARD");
 			}
 		}
 
 		// make edges from "beam_ori"
 		for (int i = 0; i < beams.size(); i++)
 		{
 			if ((beam_ori[i] & 1) == 0)
 				graph[i + 100][i + 200] = 1;
 			if ((beam_ori[i] & 2) == 0)
 				graph[i + 200][i + 100] = 1;
 		}
 
 		for (int i = 0; i < beams.size(); i++)
 		{
 			std::map<int, int> visited;
 
 			bool r1 = StartGraph(i, 1, visited);
 			visited.clear();
 			bool r2 = StartGraph(i, 2, visited);
 
 			int next_beam_ori = (r1 ? 1 : 0) + (r2 ? 2 : 0);
 			if (next_beam_ori == 0) goto hell;
 
 			if ((3 - beam_ori[i]) & next_beam_ori)
 				printf("ERROR: %d %d\n", beam_ori[i], next_beam_ori);
 			if (next_beam_ori == 3)
 			{
 				next_beam_ori = 1;
 				graph[i + 200][i + 100] = 1;
 			}
 			beam_ori[i] = next_beam_ori;
 		}
 
 		for (int i = 0; i < beams.size(); i++)
 		{
 			if (beam_ori[i] == 0)
 				map[beams[i] / 100][beams[i] % 100] = '?';
 			else if (beam_ori[i] == 1)
 				map[beams[i] / 100][beams[i] % 100] = '-';
 			else if (beam_ori[i] == 2)
 				map[beams[i] / 100][beams[i] % 100] = '|';
 			else if (beam_ori[i] == 3)
 				map[beams[i] / 100][beams[i] % 100] = '+';
 		}
 		fprintf(fout, "Case #%d: POSSIBLE\n", c_n);
 		printf("Case #%d: POSSIBLE\n", c_n);
 		for (int i = 0; i < R; i++)
 		{
 			fprintf(fout, "%s\n", map[i]);
 			printf("%s\n", map[i]);
 		}
 		continue;
 		hell:
 		fprintf(fout, "Case #%d: IMPOSSIBLE\n", c_n);
 		printf("Case #%d: IMPOSSIBLE\n", c_n);
 	}
 	return -0;
 }
