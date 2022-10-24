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
#include <cstring>
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

const int MAXH=20;
const int MAXW=20;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w;
char g[MAXH][MAXW+1];

char pat[2][2];

char gg[2*MAXH][2*MAXW+1];
bool havepat() {
	REP(x,h) REP(y,w) REP(dx,2) REP(dy,2) gg[2*x+dx][2*y+dy]=g[x][y]; REP(x,2*h) gg[x][2*w]='\0';
	REP(x,2*h-1) REP(y,2*w-1) if(gg[x][y]==pat[0][0]&&gg[x][y+1]==pat[0][1]&&gg[x+1][y]==pat[1][0]&&gg[x+1][y+1]==pat[1][1]) return true;
	return false;
}

bool been[MAXH][MAXW];
pair<int,int> q[MAXH*MAXW]; int qtail,qhead;
bool onedge[2*MAXH][2*MAXW];

int solvepat() {
	if(!havepat()) return 0;
	//printf("have: "); REP(x,2) REP(y,2) printf("%c",pat[x][y]); puts("");

	REP(x,2*h) REP(y,2*w) gg[x][y]=pat[x/h][y/w];
	vector<pair<int,int> > wopt;
	REP(x,2*h) REP(y,2*w) onedge[x][y]=false;
	REP(x,2*h) REP(y,2*w) if(gg[x][y]=='W') { REP(k,4) { int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=2*h||ny<0||ny>=2*w||gg[nx][ny]!='B') continue; onedge[x][y]=true; } if(onedge[x][y]) wopt.PB(MP(x,y)); }
	//REP(x,2*h) gg[x][2*w]='\0'; REP(x,2*h) printf("%s\n",gg[x]); printf("->%d\n",SZ(wopt)); //REPSZ(i,wopt) printf("(%d,%d)\n",wopt[i].first,wopt[i].second);

	int ret=0;
	REP(x,h) REP(y,w) been[x][y]=false;
	REP(sx,h) REP(sy,w) if(g[sx][sy]=='W') {
		REPSZ(i,wopt) {
			int xoff=wopt[i].first-sx,yoff=wopt[i].second-sy;
			qhead=qtail=0; q[qhead++]=MP(sx,sy); been[sx][sy]=true;
			while(qtail<qhead) {
				int x=q[qtail].first,y=q[qtail].second; ++qtail;
				if((x<sx||x==sx&&y<sy)&&g[x][y]=='W'&&onedge[x+xoff][y+yoff]) break;
				REP(k,4) {
					int nx=x+DX[k],ny=y+DY[k];
					if(nx<0||nx>=h||ny<0||ny>=w||been[nx][ny]) continue;
					if(nx+xoff<0||nx+xoff>=2*h||ny+yoff<0||ny+yoff>=2*w||gg[nx+xoff][ny+yoff]!=g[nx][ny]) continue;
					q[qhead++]=MP(nx,ny); been[nx][ny]=true;
				}
			}
			REP(idx,qhead) { int x=q[idx].first,y=q[idx].second; been[x][y]=false; }
			ret=max(ret,qhead);
		}
	}
	//printf("have: "); REP(x,2) REP(y,2) printf("%c",pat[x][y]); printf(" -> %d\n",ret);
	return ret;
}

int solvemono() {
	int ret=0;
	REP(x,h) REP(y,w) been[x][y]=false;
	REP(sx,h) REP(sy,w) if(!been[sx][sy]) {
		qhead=qtail=0; q[qhead++]=MP(sx,sy); been[sx][sy]=true;
		while(qtail<qhead) {
			int x=q[qtail].first,y=q[qtail].second; ++qtail;
			REP(k,4) {
				int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]!=g[x][y]||been[nx][ny]) continue;
				q[qhead++]=MP(nx,ny); been[nx][ny]=true;
			}
		}
		ret=max(ret,qhead);
	}
	return ret;
}

int solve() {
	int ret=solvemono();
	REP(a,2) REP(b,2) REP(c,2) REP(d,2) {
		if(a==b&&a==c&&a==d) continue;
		pat[0][0]=a==0?'W':'B';
		pat[0][1]=b==0?'W':'B';
		pat[1][0]=c==0?'W':'B';
		pat[1][1]=d==0?'W':'B';
		ret=max(ret,solvepat());
	}
	return ret;
}

void run(int casenr) {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	printf("Case #%d: %d\n",casenr,solve());
}

void stress() {
	REP(rep,100) {
		h=MAXH,w=MAXW; REP(x,h) REP(y,w) g[x][y]=rand()%7!=0?'W':'B'; REP(x,h) g[x][w]='\0';
		printf("Case #%d: %d\n",rep+1,solve());
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	//stress();
	return 0;
}
