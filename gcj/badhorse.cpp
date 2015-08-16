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

vector<vector<int> > adjlist;
vector<int> color;
vector<int> res;
int t;

bool dfs(int u, int col){
	if(color[u]!=-1){
		//means have visited
		if(color[u]!=col){
			return false;
		}else{
			return true;
		}
	}
	//color it as col
	color[u]=col;

	for(int i=0; i<adjlist[u].size(); i++){
		int v=adjlist[u][i];
		//color the neighbor as 1-col
		if(!dfs(v,1-col)){
			return false;
		}
	}

	return true;
}

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		cout<<"Case #"<<cas<<": ";

		int m;
		cin>>m;
        
		color=vector<int>(201,-1);
		adjlist=vector<vector<int> >(101);

        unordered_map<string,int> name2int;
        int cnt=0;
		for(int i=0; i<m; i++){
			string name1,name2;
			cin>>name1>>name2;
			if(name2int.find(name1)==name2int.end()){
				name2int[name1]=cnt++;
			}
			if(name2int.find(name2)==name2int.end()){
				name2int[name2]=cnt++;
			}
			adjlist[name2int[name1]].push_back(name2int[name2]);
			adjlist[name2int[name2]].push_back(name2int[name1]);
		}

        bool flag=true;
		for(int i=0; i<name2int.size(); i++){
			if(color[i]==-1){
				if(!dfs(i,0)){
					//color i as 0
				    flag=false;
				    break;
				}
			}

		}

		if(flag){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}

	}

}