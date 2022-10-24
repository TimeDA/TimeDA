#include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <algorithm>
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
 using namespace std;
 typedef long long ll;
 
 char buf[1000010];
 char buf2[1000010];
 vector<int> ss[22];
 int counter;
 
 int s12[100000];
 int visited[100000];
 map<string,int> s2id;
 
 int main(void) {
   int nCase;
   nCase = atoi(gets(buf));
   REP(iCase, nCase){
     int n = atoi(gets(buf));
     s2id.clear();
     REP(i, n){
       ss[i].clear();
       gets(buf);
       int pos = 0;
       for(;;){
 	int len;
 	int ret = sscanf(buf+pos, "%s%n", buf2, &len);
 // 	cerr << ret << endl;
 	if(ret == -1){
 	  break;
 	}
 	string word(buf2);
 	int id;
 	if(s2id.count(word) == 0){
 	  id = s2id.size();
 	  s2id[word] = id;
 	}else{
 	  id = s2id[word];
 	}
 	ss[i].push_back(id);
 	pos += len;
       }
     }
     int res = 1e9;
     REP(pat, 1 << n){
       if((pat & 3) != 1){
 	continue;
       }
       ++counter;
       
       int cnt = 0;
       REP(i, n){
 	REP(j, ss[i].size()){
 	  int id = ss[i][j];
 	  if(visited[id] != counter){
 	    visited[id] = counter;
 	    s12[id] = 0;
 	  }
 	  int before = s12[id];
 	  if(pat & (1 << i)){
 	    s12[id] |= 1;
 	  }else{
 	    s12[id] |= 2;
 	  }
 	  if(before != 3 && s12[id] == 3){
 	    ++cnt;
 	  }
 	}
       }
       res = min(res, cnt);
     }
     
     printf("Case #%d: %d\n", iCase+1, res);
     fflush(stdout);
   }
   return 0;
 }
