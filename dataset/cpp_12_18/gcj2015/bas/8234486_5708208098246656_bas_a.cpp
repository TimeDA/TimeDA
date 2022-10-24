#include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>
 
 using namespace std;
 	int   C, R, W;
 int main(){
 	
 	cin>>C; 
 	for(int j=0; j<C; j++){
 		cin>>R>>W;
 		vector<string> s(R, "");
 		for(int i=0; i<R; i++)cin>>s[i];
 		vector<int > ainr(R, 0);
 		vector<int > ainc(W, 0);
 		vector<int > fir(R, 200);
 		vector<int > fic(W, 200);
 		vector<int > lir(R, -1);
 		vector<int > lic(W, -1);
 		for (int i=0; i<R; i++)
 		    for(int k=0; k<W; k++)
 			if (s[i][k]=='^' ||s[i][k]=='v'||s[i][k]=='<'||
 			    s[i][k]=='>'){
 			    ainr[i]++; ainc[k]++;
 			    if(k<fir[i])fir[i]=k;
 			    if(k>lir[i])lir[i]=k;
 			    if(i<fic[k])fic[k]=i;
 			    if(i>lic[k])lic[k]=i;
 			}
 		bool bad = false;
 		for (int i=0; i<R; i++)
 		    for(int k=0; k<W; k++)
 			if (s[i][k]=='^' ||s[i][k]=='v'||s[i][k]=='<'||
 			    s[i][k]=='>')
 			    if(ainr[i]==1 && ainc[k]==1)bad=true;
 		cout<<"Case #"<<j+1<<": " ;
 		if(bad){
 		    cout<<"IMPOSSIBLE\n";
 		    continue;
 		}
 		int res=0;
 		for (int i=0; i<R; i++)
 		    for(int k=0; k<W; k++){
 			if ((s[i][k]=='^' && fic[k]==i)||(s[i][k]=='v' && lic[k]==i)||(s[i][k]=='<' && fir[i]==k)||(s[i][k]=='>' && lir[i]==k)){
 			    res++;
 			}
 		    
 		}
 		cout<<res;		
 		cout<<"\n";
 
 	}
 	
 }
