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
#include <climits>
using namespace std;

vector<vector<int> > mm;
vector<vector<bool> > vis;

int res;
int bgn;

void dfs(int x, int y, int start, int pre,int cnt){
	if(x<0 || x>=mm.size() || y<0 || y>= mm[0].size() || mm[x][y]!=pre+1){
		return;
	}
	vis[x][y]=1;

	cnt++;
	if(cnt>res){
		res=cnt;
		bgn=start;
	}else if(cnt==res){
		if(start<bgn){
			bgn=start;
		}
	}

	dfs(x+1,y,start,mm[x][y],cnt);
	dfs(x,y+1,start,mm[x][y],cnt);
	dfs(x-1,y,start,mm[x][y],cnt);
	dfs(x,y-1,start,mm[x][y],cnt);
	vis[x][y]=0;
}

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		res=1;
		bgn=1;
		cout<<"Case #"<<cas<<": ";

		int s;
		cin>>s;
		mm=vector<vector<int> >(s,vector<int>(s,0));
		vis=vector<vector<bool> >(s,vector<bool>(s,0));

		for(int i=0; i<s; i++){
			for(int j=0; j<s; j++){
				int num;
				cin>>num;
				mm[i][j]=num;
			}
		}

		for(int i=0; i<s; i++){
			for(int j=0; j<s ;j++){
				if(!vis[i][j]){
					dfs(i,j,mm[i][j],mm[i][j]-1,0);
				}
			}		
		}

		cout<<bgn<<" "<<res<<endl;
	}

}