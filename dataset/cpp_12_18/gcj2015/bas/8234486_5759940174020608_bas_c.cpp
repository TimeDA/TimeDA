#include<iostream>
 #include<vector>
 #include<string>
 #include<set>
 #include<algorithm>
 #include<sstream>
 
 using namespace std;
 	int T;
 	int N;
 set<string> get_int(set<string> a, set<string> b){
     set<string> intersect;
     set_intersection(a.begin(),a.end(),b.begin(),b.end(), inserter(intersect, intersect.begin()));
     return intersect;
 }
 set<string> get_u(set<string> a, set<string> b){
     set<string> u;
     set_union(a.begin(),a.end(),b.begin(),b.end(), inserter(u, u.begin()));
     return u;
 }
 
 set<string> make_words(string s){
     stringstream ss(s); 
     set<string> res; 
     string buf;
     while (ss >> buf) res.insert(buf);
     return res;
 }
 void prin_set(set<string> s){
 for(std::set<string>::iterator it=s.begin(); it!=s.end(); ++it)    std::cout << *it << std::endl;
 }
 int main(){
 
 	cin>>T; 
 	for(int j=0; j<T; j++){
 		cin>>N;
 		int res = 0;
 		set<string> en; en.clear();
 		set<string> fr; fr.clear();
 		vector<bool> isen(N, 0); isen[0]=1;
 		vector<bool> isfr(N, 0); isen[1]=1;
 		vector<string> data(N, "");
 		getline(cin, data[0]);
 		for(int i=0; i<N; i++){
 		    getline (cin,data[i]);
 		}
 		vector<set<string> > words(N, set<string>());
   	        for(int k=0; k<N; k++){
 		    words[k] = make_words(data[k]);
 		    }
 		en = words[0]; fr = words[1];
 	    vector<vector<set<string> > >  sav_en(2, vector<set<string> >(N));
 	    vector<vector<set<string> > >  sav_fr(2, vector<set<string> >(N));
 //	    set<string> fir = get_int(en, fr);
 	    sav_en[0][1] = sav_en[1][1] = en;
 	    sav_fr[0][1] = sav_fr[1][1] = fr;
 		    for(int k=2; k<N; k++){
 			set<string> i1 = get_int(get_u(sav_en[0][k-1], words[k]), sav_fr[0][k-1]);
 			set<string> i2 = get_int(get_u(sav_en[1][k-1], words[k]), sav_fr[1][k-1]);
 			if(i1.size()<i2.size()){
 			    sav_en[0][k] = get_u(sav_en[0][k-1], words[k]);
 			sav_fr[0][k] = sav_fr[0][ k-1];
 			}else{
 			    sav_en[0][k] = get_u(sav_en[1][k-1], words[k]);
 			sav_fr[0][k] = sav_fr[1][ k-1];
 			}
 			set<string> i3 = get_int(get_u(sav_fr[0][k-1], words[k]), sav_en[0][k-1]);
 			set<string> i4 = get_int(get_u(sav_fr[1][k-1], words[k]), sav_en[1][k-1]);
 			if(i3.size()<i4.size()){
 			    sav_fr[1][k] = get_u(sav_fr[0][k-1], words[k]);
 			sav_en[1][k] = sav_en[0][ k-1];
 			}else{
 			    sav_fr[1][k] = get_u(sav_fr[1][k-1], words[k]);
 			sav_en[1][k] = sav_en[1][ k-1];
 			}
 		    }
 //		prin_set(get_int(sav_en[0][N-1], sav_fr[0][N-1]));
 //		cout<<"----";
 		int ii = get_int(sav_en[0][N-1], sav_fr[0][N-1]).size();
 		int ii2 = get_int(sav_en[1][N-1], sav_fr[1][N-1]).size();
 		res = min(ii, ii2);
 		cout<<"Case #"<<j+1<<": "<<res<<"\n" ;
 
 	}
 	
 }
