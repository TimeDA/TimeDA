#include <cstdio>
 #include <cstring>
 #include <cstdlib>
 
 using namespace std;
 
 double table[1 << 20];
 int n;
 char s[250];
 
 double go(int bit) {
 	double ret = -1;
   int same[25];
 	for (int i = 0; i < n; ++i) {
 		same[i] = bit;
 		int last = (bit & 1);
 		bit = (bit >> 1) + ((last == 1) ? (1 << (n - 1)) : 0);
 		if (table[same[i]] > -0.5) ret = table[same[i]];
 	}
 	if (ret > -0.5) {
 		for (int i = 0; i < n; ++i)
 			table[same[i]] = ret;
 		return ret;
 	}
 
 	ret = 0;
 	for (int i = 0; i < n; ++i) {
 		int pay = n;
 		for (int j = 0; j < n; ++j) {
 			if ((same[i] & (1 << j)) == (1 << j)) {
 				pay--;
 			} else {
 				ret += (pay + go(same[i] | (1 << j)));
 				break;
 			}
 		}
 	}
 
 	ret /= n;
 
 	for (int i = 0; i < n; ++i)
 		table[same[i]] = ret;
 	return ret;
 }
 
 int main() {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn) {
 		memset(table, -1, sizeof(table));
 		scanf("%s", s);
 		n = strlen(s);
 		int bit = 0;
 		for (int i = 0; i < n; ++i)
 			if (s[i] == 'X') bit |= (1 << i);
 		table[(1 << n) - 1] = 0;
 
 		printf("Case #%d: %.13lf\n", cn, go(bit));
 	}
 }
