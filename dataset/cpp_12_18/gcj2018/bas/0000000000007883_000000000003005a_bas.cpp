#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int C;
int main(){
	
    cin>>C; 
    for(int cc=0; cc<C; cc++){
	int r,c, h, v;
        cin>>r>>c>>h>>v;
	vector<string> s(r);
	for(int i=0; i<r; i++)cin>>s[i];    
	vector<int> inrow(r, 0), incol(c,0);
	int tot =0;
	for(int i=0; i<r; i++){
	    for(int j=0; j<c; j++){
		if(s[i][j]=='@'){inrow[i]++; incol[j]++; tot++;}
	    }
	}
	int cells = (h+1)*(v+1);
	if(tot%cells){
	    cout<<"Case #"<<cc+1<<": ";
	    cout<<"IMPOSSIBLE\n";
	    continue;

	}else if(tot==0){
	    cout<<"Case #"<<cc+1<<": ";
	    cout<<"POSSIBLE\n";
	    continue;
	}
	int rowtot = tot/(h+1);
	int coltot = tot/(v+1);
	int incell = tot/cells;
	int ind=0; int curcol = 0;
	vector<int> vdivs(1,0);
	bool bad =false;
	while(ind<c){
	    curcol+=incol[ind];
	    if(curcol==coltot){
		vdivs.push_back(ind+1);
		curcol=0;
	    } else if(curcol>coltot){
		bad =true; break;
	    }
	    ind++;
	}
	vdivs.push_back(c);

	ind=0; int currow = 0;
	vector<int> hdivs(1,0);
	while(!bad && ind<r){
	    currow+=inrow[ind];
	    if(currow==rowtot){
		hdivs.push_back(ind+1);
		currow=0;
	    } else if(currow>rowtot){
		bad =true; break;
	    }
	    ind++;
	}
	hdivs.push_back(r);
	
	for(int i=0; i<=h && !bad; i++){
	    for(int j=0; j<=v; j++){
		int num=0;
		for(int ii=hdivs[i]; ii<hdivs[i+1]; ii++)
		    for(int jj=vdivs[j]; jj<vdivs[j+1]; jj++)
			if(s[ii][jj]=='@')num++;
		if(num!=incell){
		    bad=true; break;
		}
	    }

	}

        cout<<"Case #"<<cc+1<<": ";

	if( bad){
	    cout<<"IMPOSSIBLE\n";
	}else{
	    cout<<"POSSIBLE\n";
	}
    }
	
}
