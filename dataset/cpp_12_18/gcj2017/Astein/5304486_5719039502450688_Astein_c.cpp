#define _CRT_SECURE_NO_WARNINGS
 
 #include <cstdio>
 #include <cstring>
 #include <iostream>
 #include <vector>
 #include <string>
 #include <map>
 #include <algorithm>
 
 using namespace std;
 
 int simulate(int Hd, int Ad, int Hk, int Ak, int B, int D, int cb, int cd)
 {
 	int maxHd = Hd;
 	int turn = 0;
 	string ts;
 	while (true)
 	{
 		turn++;
 		if (cd == 0 && 2 * Ak >= maxHd) return 789789789;
 		if (Ad >= Hk)
 		{
 			ts += "A";
 			break; // ATTACK
 		}
 		else if ((cd == 0 && Ak >= Hd) || (cd > 0 && Ak - D >= Hd))
 		{
 			if (2 * Ak >= maxHd) return 789789789;
 			Hd = maxHd;
 			ts += "C";
 		}
 		else if (cd > 0)
 		{
 			Ak -= D;
 			cd--;
 			if (Ak < 0) Ak = 0;
 			ts += "D";
 		}
 		else if (cb > 0)
 		{
 			Ad += B;
 			cb--;
 			ts += "B";
 		}
 		else
 		{
 			Hk -= Ad;
 			ts += "A";
 		}
 
 		Hd -= Ak; // knight's ATTACK
 	}
 	return turn;
 }
 
 int main()
 {
 	freopen("C-small-attempt4.in", "r", stdin);
 	freopen("C-small-attempt4.out", "w", stdout);
 
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int Hd, Ad, Hk, Ak, B, D;
 		scanf("%d%d%d%d%d%d", &Hd, &Ad, &Hk, &Ak, &B, &D);
 		printf("Case #%d: ", cn);
 
 		if (Ad >= Hk)
 		{
 			printf("1\n");
 			continue;
 		}
 		if (Ak - D >= Hd)
 		{
 			printf("IMPOSSIBLE\n");
 			continue;
 		}
 		if (Ad + Ad >= Hk || Ad + B >= Hk)
 		{
 			printf("2\n");
 			continue;
 		}
 
 		int ret = 789789789;
 		for (int cd = 0; cd <= Ak; ++cd)
 		{
 			if (D == 0 && cd == 1) break;
 
 			for (int cb = 0; cb <= Hk; ++cb)
 			{
 				if (B == 0 && cb == 1) break;
 
 				int lad = Ad + cb * B;
 				int turn = simulate(Hd, Ad, Hk, Ak, B, D, cb, cd);
 				ret = std::min(turn, ret);
 
 				if (lad >= Hk) break;
 			}
 
 			if (cd * D > Ak) break;
 		}
 		if (ret == 789789789)
 		{
 			printf("IMPOSSIBLE\n");
 			continue;
 		}
 
 		printf("%d\n", ret);
 	}
 }