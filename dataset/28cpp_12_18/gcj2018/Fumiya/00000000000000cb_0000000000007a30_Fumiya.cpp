#include <iostream>
#include <vector>

using namespace std;

void solve(){
	int A; cin >> A;
	const int h = (A==20 ? 4 : 14);
	const int w = h + 1;
	vector<vector<int>> field(20, vector<int>(20, 0));
	for(int _=0;_<1000;_++){
		int px = 0, py = 0, m = 0;
		for(int y=1;y+1<h;y++){
			for(int x=1;x+1<w;x++){
				int c = 0;
				for(int dy=-1;dy<=1;dy++){
					for(int dx=-1;dx<=1;dx++){
						c += 1 - field[y+dy][x+dx];
					}
				}
				if(c > m){ px = x; py = y; }
			}
		}
		cout << px+1 << " " << py+1 << endl;
		cin >> px >> py;
		if(px <= 0 && py <= 0) break;
		field[py-1][px-1] = 1;
	}
}

int main(){
	int T; cin >> T;
	while(T--) solve();
}

