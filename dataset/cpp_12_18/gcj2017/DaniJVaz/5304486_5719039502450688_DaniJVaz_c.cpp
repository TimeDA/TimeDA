#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 ll test(ll hd, ll ad, ll hk, ll ak, ll b, ll d, ll bi, ll di) {
 	// We do bi buffs, di debuffs, and then attack and cure as needed
 	// We do first debuffs, then buffs, then attacks, with heals as needed
 
 	ll rounds = 0;
 	ll chd = hd;
 
 	if (di > 0) {
 		for (int i=0; i<di; i++) {
 			ak  -= d;
 			if (ak < 0) ak = 0;
 			chd -= ak;
 			++rounds;
 
 			if (chd <= 0)
 				return -1;
 
 			if (i != di-1 and chd <= (ak-d)) {
 				chd = hd - ak;
 				if (chd <= 0)
 					return -1;
 				++rounds;
 			}
 		}
 	}
 
 	if (bi > 0) {
 		if (chd <= ak) {
 			chd = hd - ak;
 			if (chd <= 0)
 				return -1;
 			++rounds;
 		}
 
 		for (int i=0; i<bi; i++) {
 			ad  += b;
 			chd -= ak;
 			++rounds;
 
 			if (chd <= 0)
 				return -1;
 
 			if (i != bi-1 and chd <= ak) {
 				chd = hd - ak;
 				if (chd <= 0)
 					return -1;
 				++rounds;
 			}
 		}
 	}
 
 	if (ad >= hk)
 		return rounds + 1;
 
 	if (chd <= ak) {
 		chd = hd - ak;
 		if (chd <= 0)
 			return -1;
 		++rounds;
 	}
 
 	while (1) {
 		hk  -= ad;
 		chd -= ak;
 		++rounds;
 
 		if (hk <= 0)
 			return rounds;
 
 		if (chd <= 0)
 			return -1;
 
 		if (ad >= hk)
 			return rounds + 1;
 
 		if (chd <= ak) {
 			chd = hd - ak;
 			if (chd <= 0)
 				return -1;
 			++rounds;
 		}
 	}
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		ll hd, ad, hk, ak, b, d;
 		scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &hd ,&ad, &hk, &ak, &b, &d);
 		// printf("%I64d %I64d %I64d %I64d %I64d %I64d\n", hd ,ad, hk, ak, b, d);
 
 		ll minRounds = -1;
 		for (ll bi = 0; bi <= hk; bi++) {
 			for (ll di = 0; di <= ak; di++) {
 				ll rounds = test(hd, ad, hk, ak, b, d, bi, di);
 				// printf("%I64d %I64d %I64d\n", bi, di, rounds);
 				if (rounds > -1) {
 					if (minRounds == -1 or minRounds > rounds)
 						minRounds = rounds;
 				}
 			}
 		}
 
 		printf("Case #%d: ", iC);
 		if (minRounds == -1)
 			printf("IMPOSSIBLE\n");
 		else
 			printf("%I64d\n", minRounds);
 	}
 	return 0;
 }