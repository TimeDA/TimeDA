#include <iostream>
 #include <queue>
 #include <cstring>
 
 using namespace std;
 
 int mem[101][101][101][101];
 
 struct State {
 	int Hd, Ad, Hk, Ak;
 	int turn;
 	State(int hd=0, int ad=0, int hk=0, int ak=0, int t=0) : Hd(hd), Ad(ad), Hk(hk), Ak(ak), turn(t){}
 };
 
 void solveSmall(){
 	int Hd, Ad, Hk, Ak, B, D;
 	cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
 	memset(mem, -1, sizeof(mem));
 	queue<State> qu; qu.push(State(Hd, Ad, Hk, Ak, 0));
 	mem[Hd][Ad][Hk][Ak] = 0;
 	while(!qu.empty()){
 		State s = qu.front(); qu.pop();
 
 		auto enemyAttack = [&](State& cs){
 			cs.Hd -= cs.Ak;
 			cs.Hd = max(cs.Hd, 0);
 			cs.turn++;
 			if(mem[cs.Hd][cs.Ad][cs.Hk][cs.Ak] == -1){
 				mem[cs.Hd][cs.Ad][cs.Hk][cs.Ak] = cs.turn;
 				if(cs.Hd > 0) qu.push(cs);
 			}
 		};
 
 		// Attack
 		{
 			State ns = s;
 			ns.Hk -= ns.Ad;
 			if(ns.Hk <= 0){
 				cout << s.turn + 1 << endl;
 				return;
 			}
 			enemyAttack(ns);
 		}
 		// Buff
 		{
 			State ns = s;
 			ns.Ad = min(ns.Hk, ns.Ad + B);
 			enemyAttack(ns);
 		}
 		// Cure
 		{
 			State ns = s;
 			ns.Hd = Hd;
 			enemyAttack(ns);
 		}
 		// Debuff
 		{
 			State ns = s;
 			ns.Ak = max(0, ns.Ak - D);
 			enemyAttack(ns);
 		}
 	}
 	cout << "IMPOSSIBLE" << endl;
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		printf("Case #%d: ", t);
 		solveSmall();
 	}
 }
