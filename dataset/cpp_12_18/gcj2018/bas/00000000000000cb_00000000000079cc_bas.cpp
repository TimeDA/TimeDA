#include<bits/stdc++.h>
#define eps 1e-10
using namespace std;
	int T;
	double a;
void rotz(vector<vector<double> > & p1, double ang, vector<vector<double> > & res){
    for(int i=0; i<p1.size(); i++){
    res[i][2] = p1[i][2];
    res[i][0] = p1[i][0] * cos(ang) - p1[i][1]*sin(ang);
    res[i][1] = p1[i][0] * sin(ang) + p1[i][1]*cos(ang);
    }
}
double area(vector<vector<double > > & p){
    double a1 = (p[1][0]-p[0][0])*sqrt(2.0)/2;
    double a2 = (0.0-p[1][0])*sqrt(2.0);
//    cout<<a1<<" "<<a2<<"\n";
    double res = (a1+a2)*2;
    return res;
}
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
	    cin>>a;
	    vector<vector<double> > points(3);
	    vector<vector<double> > corners(3);
//cout<<1; cout.flush();
	    points[0] = {0,0.5,0};
	    points[1] = {sqrt(2.0)/4, 0, sqrt(2.0)/4};
	    points[2] = {sqrt(2.0)/4, 0, -sqrt(2.0)/4};
	    corners[0] = {-sqrt(2.0)/2,0.5,0};
	    corners[1] = {0,0.5,-sqrt(2.0)/2};
	    corners[2] = {0,0.5,sqrt(2.0)/2};
//cout<<1; cout.flush();
	    double res =0;
	    double l = 0; double r = acos(1.0/sqrt(3.0));
	    while(true){
//cout<<1; cout.flush();
		res = ( l+r)/2;
		vector<vector<double> > tmp(3, vector<double>(3));
		rotz(corners, res, tmp);
//for(int i=0; i<3; i++){
//    cout<<tmp[i][0]<<","<<tmp[i][1]<<","<<tmp[i][2]<<"\n";
//}
		double tar = area(tmp);
		if(fabs(tar-a)<eps){	
		    break;
		}
		if(tar>a){
		    r = res;
		}else{
		    l=res;
		}	
//cout<<tar<<" "<<res<<"\n";		
	    }

	    
	    cout<<"Case #"<<j+1<<":\n";
	    cout<<setprecision(15);
		vector<vector<double> > tmp(3, vector<double>(3));
		rotz(points,res,  tmp);
	    for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)cout<<tmp[i][j]<<" ";
		cout<<"\n";
	    }
		
		
	}
	
}
