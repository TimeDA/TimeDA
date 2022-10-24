#include <algorithm>  
 #include <iostream>  
 #include <sstream>  
 #include <string>  
 #include <vector>  
 #include <queue>  
 #include <set>  
 #include <map>  
 #include <cstdio>  
 #include <cstdlib>  
 #include <cctype>  
 #include <cmath>  
 #include <list>  
 #include <climits>
 #include <cassert>
 using namespace std;  
 
 #define PB push_back  
 #define MP make_pair  
 #define SZ(v) ((int)(v).size())  
 #define FOR(i,a,b) for(int i=(a);i<(b);++i)  
 #define REP(i,n) FOR(i,0,n)  
 #define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
 #define REPE(i,n) FORE(i,0,n)  
 #define FORSZ(i,a,v) FOR(i,a,SZ(v))  
 #define REPSZ(i,v) REP(i,SZ(v))  
 typedef long long ll;  
 
 const int MAXSEQ=200-2;
 const int MAXKNOWNSEQWORDS=1000;
 const int MAXUNKNOWNSEQWORDS=10;
 const int MAXWORDLEN=10;
 const int MAXWORDS=2*MAXKNOWNSEQWORDS+MAXSEQ*MAXUNKNOWNSEQWORDS;
 
 char buff[(MAXWORDLEN+1)*MAXKNOWNSEQWORDS];
 char word[MAXWORDLEN+1];
 map<string,int> words;
 
 int nseq;
 int known[2][MAXKNOWNSEQWORDS]; int nknown[2];
 int unknown[MAXSEQ][MAXUNKNOWNSEQWORDS]; int nunknown[MAXSEQ];
 
 int lang[MAXWORDS];
 
 void run(int casenr) {
 	gets(buff); sscanf(buff,"%d",&nseq); nseq-=2;
 	words.clear();
 	REP(i,2) {
 		gets(buff); nknown[i]=0;
 		char* at=buff; while(sscanf(at,"%s",word)==1) { while(*at==' ') ++at; if(!words.count(word)) words[word]=SZ(words); known[i][nknown[i]++]=words[word]; at+=strlen(word); }
 	}
 	REP(i,nseq) {
 		gets(buff); nunknown[i]=0;
 		char* at=buff; while(sscanf(at,"%s",word)==1) { while(*at==' ') ++at; if(!words.count(word)) words[word]=SZ(words); unknown[i][nunknown[i]++]=words[word]; at+=strlen(word); }
 	}
 	//REP(i,2) { printf("%d:",nknown[i]); REP(j,nknown[i]) printf(" %d",known[i][j]); puts(""); }
 	//REP(i,nseq) { printf("%d:",nunknown[i]); REP(j,nunknown[i]) printf(" %d",unknown[i][j]); puts(""); }
 	//puts("");
 
 	int ret=INT_MAX,nwords=SZ(words);
 	REP(i,1<<nseq) {
 		REP(j,nwords) lang[j]=0;
 		REP(j,2) REP(k,nknown[j]) lang[known[j][k]]|=1<<j;
 		REP(j,nseq) REP(k,nunknown[j]) lang[unknown[j][k]]|=1<<(i&(1<<j)?1:0);
 		int cur=0; REP(j,nwords) if(lang[j]==3) ++cur; if(cur<ret) ret=cur;
 	}
 	printf("Case #%d: %d\n",casenr,ret);
 }
 
 int main() {
 	gets(buff); int n; sscanf(buff,"%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
