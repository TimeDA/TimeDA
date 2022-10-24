#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 #include <bitset>
 #include <string>
 #include <iostream>
 
 typedef long long ll;
 
 using namespace std;
 
 int main() {
 	int iC=0, nC;
 	string line;
 	getline(cin, line);
 	sscanf(line.c_str(), "%d", &nC);
 
 	for (iC=1; iC<=nC; iC++) {
 		getline(cin, line);
 
 		int n;
 		sscanf(line.c_str(), "%d", &n);
 
 		map<string, int> wordmap;
 		int nextInd = 0;
 		vector<int> words[n];
 		for (int i=0; i<n; i++) {
 			getline(cin, line);
 			//printf("%s\n", line.c_str());
 			int s=0, e=0;
 			while (line[e] != '\n' and line[e] != '\r' and line[e] != '\0') {
 				if (line[e] == ' ') {
 					string w = line.substr(s, e-s);
 					if (wordmap.count(w) == 0)
 						wordmap[w] = nextInd++;
 					words[i].push_back(wordmap[w]);
 					s = e+1;
 				}
 				e++;
 			}
 
 			string w = line.substr(s, e-s);
 			if (wordmap.count(w) == 0)
 				wordmap[w] = nextInd++;
 			words[i].push_back(wordmap[w]);
 		}
 
 		bitset<100000> baseEnglishSet, baseFrenchSet;
 		for (int l=0; l<(int)words[0].size(); l++)
 			baseEnglishSet.set(words[0][l]);
 		for (int l=0; l<(int)words[1].size(); l++)
 			baseFrenchSet.set(words[1][l]);
 
 		bitset<100000> englishSet, frenchSet;
 		int minCount = 10000000;
 		for (int i=2; i<(1LL<<n); i+=4) {
 			englishSet = baseEnglishSet;
 			frenchSet = baseFrenchSet;
 
 			for (int j=2; j<n; j++) {
 				bool english = (i & (1LL << j)) == 0;
 				for (int l=0; l<(int)words[j].size(); l++) {
 					if (english)
 						englishSet.set(words[j][l]);
 					else
 						frenchSet.set(words[j][l]);
 				}
 			}
 
 			int count = 0;
 			for (int i=0; i<(int)wordmap.size(); i++)
 				if (englishSet[i] && frenchSet[i])
 					count++;
 			minCount = min(minCount, count);
 		}
 
 
 		printf("Case #%d: %d\n", iC, minCount);
 	}
 	return 0;
 }
 
 
