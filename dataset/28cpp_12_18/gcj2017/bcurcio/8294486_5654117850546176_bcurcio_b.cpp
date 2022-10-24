#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 
 #define MP make_pair
 #define PB push_back
 #define SZ(X) ((int)(X.size()))
 #define LEN(X) ((int)(X.length()))
 #define all(X) (X).begin(), (X).end()
 
 typedef long long ll;
 typedef vector<int> vint;
 typedef vector<vint> vvint;
 typedef pair<int,int> pint;
 typedef vector<pint> vpint;
 typedef vector<string> vstr;
 typedef unsigned long long ull;
 
 const ull INF = 18446744073709551615LL;
 
 struct Edge {
   int from, to, index;
   int cap,flow;
   Edge(int from, int to, int cap, int  flow, int index) :
     from(from), to(to), cap(cap), flow(flow), index(index) {}
 };
 
 struct Dinic {
   int N;
   vector<vector<Edge> > G;
   vector<Edge *> dad;
   vector<int> Q;
   
   Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
   
   void AddEdge(int from, int to, int cap) {
 	  //~ cerr << "E " << from << ' ' << to << ' ' << cap << endl;
     G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
     if (from == to) G[from].back().index++;
     G[to].push_back(Edge(to, from, cap, 0, G[from].size() - 1));
   }
 
   ull BlockingFlow(int s, int t) {
     fill(dad.begin(), dad.end(), (Edge *) NULL);
     dad[s] = &G[0][0] - 1;
     
     int head = 0, tail = 0;
     Q[tail++] = s;
     while (head < tail) {
       int x = Q[head++];
       for (int i = 0; i < G[x].size(); i++) {
         Edge &e = G[x][i];
         if (!dad[e.to] && e.cap - e.flow > 0) {
           dad[e.to] = &G[x][i];
           Q[tail++] = e.to;
         }
       }
     }
     if (!dad[t]) return 0;
 
     ull totflow = 0;
     for (int i = 0; i < G[t].size(); i++) {
       Edge *start = &G[G[t][i].to][G[t][i].index];
       ull amt = INF;
       for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
         if (!e) { amt = 0; break; }
         amt = min(amt,(ull)e->cap - e->flow);
       }
       if (amt == 0) continue;
       for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
         e->flow += amt;
         G[e->to][e->index].flow -= amt;
       }
       totflow += amt;
     }
     return totflow;
   }
 
   ull GetMaxFlow(int s, int t) {
     ull totflow = 0;
     while (ull flow = BlockingFlow(s, t))
       totflow += flow;
     return totflow;
   }
   
   void show(int s,int n){
 	  int cur = s;
 	  int cnt = 0;
 	  
 	  string wds = "ROYGBV";
 	  
 	  //~ cerr << "entra " << endl;
 	  int cant[6] ={0};
 	  
 	  for(int i=0;i<(int)G[s].size();i++) cant[G[s][i].to] = G[s][i].flow; 
 	  int antP = -1;
 	  while(cnt < n){
 		  
 		  bool can = false;
 		  
 		  if(cur != s){
 			  for(int i=0;i<(int)G[cur].size();i++) if(G[cur][i].to < s){
 				  if(G[cur][i].flow>0){
 					  
 					  int ant = cur;
 					  G[cur][i].flow--;
 					  cur  =  G[cur][i].to - 6;
 					  
 					  if(cur == ant){
 						  cout << "eror" << endl;
 						  exit(1);
 					  }
 					  if(cant[cur]<=0) continue;
 					  
 					  cant[cur]--;
 					  cout << wds[cur] ;
 					  antP = cur;
 					  can = true;
 					  cnt++;
 					  break;
 				  }
 				  
 			  }
 			}
 			
 		  if(cur == s){
 			  for(int i=0;i<(int)G[cur].size();i++){
 				  if(G[cur][i].flow>0 && cant[G[cur][i].to]>0 && antP!=G[cur][i].to){
 					  
 					  G[cur][i].flow--;
 					  cur  =  G[cur][i].to;
 					  
 					  if(cant[cur]<=0) continue;
 					  
 					  cant[cur]--;
 					  cout << wds[cur] ;
 					  antP = cur;
 					  can = true;
 					  cnt++;
 					  break;
 				  }
 				  
 			  }
 		  }
 		  
 		  if(!can) cur = s;
 		  
 	  }
 	  //~ cerr << "sale " << endl;
 	  
 	  cout << endl;
   }
 };
 
 void solve(){
 	//~ int r,o,y,g,b,v;
 	int colors[6];	// roygbv
 	int n;
 	cin >> n;
 	int horse = 0;
 	
 	for(int i=0;i<6;i++){
 		cin >> colors[i];
 		horse+=colors[i];
 		//~ cerr <<"* " << i << ' ' << colors[i] << endl;
 	}
 	
 	int nodes = 6*2+2;
 	Dinic graph(nodes);
 	int start = nodes-2;
 	int end  = nodes-1;
 	
 	for(int i=0;i<6;i++) if(colors[i]>0){
 		graph.AddEdge(start,i,colors[i]);
 		graph.AddEdge(i+6,end,colors[i]);
 		
 		for(int j=0;j<6;j++) if(colors[j]>0){
 			if(i==0 && j==0) continue;
 			if(i==0 && j==1) continue;
 			if(i==0 && j==5) continue;
 			
 			if(i==1 && j!=4) continue;
 			
 			if(i==2 && j==2) continue;
 			if(i==2 && j==1) continue;
 			if(i==2 && j==3) continue;
 			
 			if(i==3 && j!=0) continue;
 			
 			if(i==4 && j==4) continue;
 			if(i==4 && j==3) continue;
 			if(i==4 && j==5) continue;
 			
 			if(i==5 && j!=2) continue;
 			//~ cerr << i << ' ' << j << endl;
 			graph.AddEdge(i,6+j,min(colors[i],colors[j]));
 		}
 	}
 	//~ cerr << " pp " << endl;
 	int ans = graph.GetMaxFlow(start,end);
 	
 	if(ans!=n){
 		cout << "IMPOSSIBLE" << endl;
 	}else{
 		//~ cerr << "llega " << endl;
 		graph.show(start,n);
 	}
 	
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout << "Case #"<<i+1<<": ";
       solve();
   }
 }
