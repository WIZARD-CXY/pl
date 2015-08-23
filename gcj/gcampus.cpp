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

void print(map<pair<int,int>,int> &roadidx){
  for(auto it : roadidx){
    cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
  }
}
void dijk(int n, int src, vector<vector<int> > &G, vector<int> &vis, 
	     vector<int> &dist, set<int> &used, map<pair<int,int>,int> &roadidx){
      for(int i=0; i<n; i++){
          dist[i]=G[src][i];
      }
      
       dist[src]=0;
       vis[src]=1;

      for(int j=0; j<n; j++){
         int minDst=INT_MAX;
         int minIdx=-1;
         for(int i=0; i<n; i++){
              if(!vis[i] && dist[i] <minDst){
                    minDst=dist[i];
                    minIdx= i;
              }
         }

         if(minIdx==-1){
          break;
         }

         vis[minIdx]=1;

        //relaxation
        for(int i=0; i<n; i++){
            if(!vis[i] && G[minIdx][i]<INT_MAX && (dist[minIdx]+G[minIdx][i])<=dist[i]){
                dist[i]=dist[minIdx]+G[minIdx][i];
                used.insert(roadidx[{minIdx,i}]);

            }
        }
      }
}

int main(int argc, char* argv[]){
    // first parameter is testfile name
  	freopen(argv[1],"r",stdin);
      
    int t;
  	cin>>t;

  	for(int cas=1; cas<=t; cas++){
    		cout<<"Case #"<<cas<<":"<<endl;
    		int n,m;
    		cin>>n>>m;

    		vector<vector<int> > G(n,vector<int>(n,INT_MAX));
    		vector<int> dist(n,INT_MAX);

    		set<int> res;
        set<int> used;
    		map<pair<int,int>,int> roadidx;
    		vector<int> vis(n,0);

    		for(int i=0; i<m; i++){
    			int u,v,c;
    			cin>>u>>v>>c;

    			if(G[u][v]!=INT_MAX){

    				if(c>G[u][v]){
    					//redundant road
    					used.insert(i);

    				}else if (c<G[u][v]){
    					//find smaller road
    					res.insert(roadidx[{u,v}]);
    					G[u][v]=c;
    			    G[v][u]=c;
              roadidx[make_pair(u,v)]=i;
              roadidx[make_pair(v,u)]=i;

            }else{

            }

    			}else{
    				//new road
    				G[u][v]=c;
    			  G[v][u]=c;
            roadidx[make_pair(u,v)]=i;
            roadidx[make_pair(v,u)]=i;
    			}
    		}

        //print(roadidx);

        for(int i=0; i<n; i++){
          dijk(n,i,G,vis,dist,used,roadidx);
        }

        for(int i=0; i<m; i++){
          if(used.find(i)==used.end()){
            res.insert(i);
          }
        }

        if(res.size()==0){
          cout<<endl;
        }else{
          for(auto r: res){
            cout<<r<<endl;
          }
        }
    }
}