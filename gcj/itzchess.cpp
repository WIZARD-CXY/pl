#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>
#include <unordered_map>
using namespace std;
int mm[8][8];

struct player{
	int x,y;
	int type;// 0 is k,1 is q,2 is r, 3 is b ,4 is n, 5 is p
	int numdir; // number of dir he can move
	int maxstep;// number of step he can move
};
vector<vector<pair<int,int> >> dxy;

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;
	
	vector<pair<int,int> > kpath={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{-1,-1},{1,1},{1,-1}};
	vector<pair<int,int> > qpath={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{-1,-1},{1,1},{1,-1}};
	vector<pair<int,int> > rpath={{-1,0},{1,0},{0,-1},{0,1}};
	vector<pair<int,int> > bpath={{-1,1},{-1,-1},{1,1},{1,-1}};
	vector<pair<int,int> > npath={{-2,-1},{-1,-2},{1,-2},{2,-1},{1,2},{2,1},{-2,1},{-1,2}};
	vector<pair<int,int> > ppath={{1,1},{1,-1}};
	dxy.push_back(kpath);
	dxy.push_back(qpath);
	dxy.push_back(rpath);
	dxy.push_back(bpath);
	dxy.push_back(npath);
	dxy.push_back(ppath);

	vector<player> players;

	for(int cas=1; cas<=t; cas++){
		players.clear();
		memset(mm,0,sizeof(mm));
		cout<<"Case #"<<cas<<": ";

		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			string s;
			cin>>s;

			int row=s[0]-'A';
			int col=s[1]-'1';
			player p;
			p.x=row;
			p.y=col;

			char type=s[3];
			switch (type){
				case 'K':
				p.type=0;
				p.numdir=8;
				p.maxstep=1;
				break;
				case 'Q':
				p.type=1;
				p.numdir=8;
				p.maxstep=50;
				break;
				case 'R':
				p.type=2;
				p.numdir=4;
				p.maxstep=50;
				break;
				case 'B':
				p.type=3;
				p.numdir=4;
				p.maxstep=50;
				break;
				case 'N':
				p.type=4;
				p.numdir=8;
				p.maxstep=1;
				break;
				case 'P':
				p.type=5;
				p.numdir=2;
				p.maxstep=1;
				break;
			}
			players.push_back(p);
			mm[row][col]=1;
		}

		int ans=0;

		for(int i=0; i<n; i++){
			for(int k=0; k<players[i].numdir; k++){
				int sx=players[i].x;
				int sy=players[i].y;
                
                // stretch torwards k direction
				for(int step=1; step<=players[i].maxstep; step++){
					int newx=sx+(dxy[players[i].type][k].first)*step;
					int newy=sy+(dxy[players[i].type][k].second)*step;

					if(newx<0 || newx >=8 || newy<0 || newy >=8){
						//out of range
						break;
					}

					if(mm[newx][newy]){
						//cout<<"player "<<i<<endl;
						//cout<<sx<<" "<<sy<<" "<<newx<<" "<<newy<<endl;
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}

}