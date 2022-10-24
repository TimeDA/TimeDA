#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <string>
 
 typedef long long ll;
 
 using namespace std;
 
 string recExplore(int r, int p, int s, string lineup = "") {
 	if (r+p+s == 0) {
 		string roundd = lineup;
 		while (roundd.length() > 1) {
 			//printf("%s\n", roundd.c_str());
 			string temp = "";
 			for (int i=0; i<(int)roundd.size(); i+=2) {
 				if (roundd[i] == roundd[i+1])
 					return "";
 				if ((roundd[i] == 'P' and roundd[i+1] == 'S') or (roundd[i] == 'S' and roundd[i+1] == 'P'))
 					temp += "S";
 				if ((roundd[i] == 'P' and roundd[i+1] == 'R') or (roundd[i] == 'R' and roundd[i+1] == 'P'))
 					temp += "P";
 				if ((roundd[i] == 'R' and roundd[i+1] == 'S') or (roundd[i] == 'S' and roundd[i+1] == 'R'))
 					temp += "R";
 			}
 			roundd = temp;
 		}
 		return lineup;
 	}
 
 	if (p > 0) {
 		string temp = recExplore(r, p-1, s, lineup + "P");
 		if (temp.length()>0)
 			return temp;
 	}
 
 	if (r > 0) {
 		string temp = recExplore(r-1, p, s, lineup + "R");
 		if (temp.length()>0)
 			return temp;
 	}
 
 	if (s > 0) {
 		string temp = recExplore(r, p, s-1, lineup + "S");
 		if (temp.length()>0)
 			return temp;
 	}
 
 	return "";
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int N, R, P, S;
 		scanf("%d %d %d %d", &N, &R, &P, &S);
 
 		string lineup = recExplore(R, P, S, "");
 
 		if (lineup == "")
 			lineup = "IMPOSSIBLE";
 
 		printf("Case #%d: %s\n", iC, lineup.c_str());
 	}
 	return 0;
 }