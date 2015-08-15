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
vector<bool> vis;
vector<int> res;
int t;

bool dfs(int u){
	vis[u]=-1;
    
    for(int i=0; i<adjlist[u].size(); i++){
    	int v=adjlist[u][i];
    	if(vis[v]<0){
    		return false;
    	}else if(!vis[v] && !dfs(v)){
    		return false;
    	}
    }

	vis[u]=1;
	res[t--]=u;
	return true;
}

bool toposort(int n){
	t=n-1;
	for(int i=0; i<n; i++){
		if(!vis[i]){
			if(!dfs(i)){
				return false;
			}
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

		int n;
		cin>>n;
		adjlist=vector<vector<int> >(n+1);
		vis=vector<bool>(n+1,0);
		res=vector<int>(n+1,0);
		unordered_map<string,int> name2int;
		unordered_map<int,string> int2name;

        int cnt=0;
		for(int i=0; i<n; i++){
			string st,en;
			cin>>st>>en;
			
			if(name2int.find(st)==name2int.end()){
				//map name to a digit
				name2int[st]=cnt++;
				int2name[cnt-1]=st;
			}
			if(name2int.find(en)==name2int.end()){
				//map name to a digit
				name2int[en]=cnt++;
				int2name[cnt-1]=en;
			}
			adjlist[name2int[st]].push_back(name2int[en]);
		}

		toposort(n+1);

		bool first=1;

		for(int i=0; i<n; i++){
			if(first){
				cout<<int2name[res[i]]<<"-"<<int2name[res[i+1]];
				first=0;
			}else{
				cout<<" "<<int2name[res[i]]<<"-"<<int2name[res[i+1]];
			}
			
		}
		cout<<endl;
	}

}