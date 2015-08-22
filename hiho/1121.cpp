#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	freopen("test.in","r",stdin);
	int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		int n,m;
		cin>>n>>m;

		vector<int> color(n+1,-1);
		vector<vector<int> > G(n+1);

		for(int i=0; i<m;i++){
			int u,v;
			cin>>u>>v;

			G[u].push_back(v);
			G[v].push_back(u);
		}
		bool flag=true;
		
        for(int i=1; i<=n; i++){
        	if(color[i]==-1){
        		queue<int> qq;
				color[i]=0;
				qq.push(i);
				
				while(!qq.empty()){
					int u=qq.front();
					qq.pop();

					for(int i=0; i<G[u].size(); i++){
						int v=G[u][i];
						if(color[v]==-1){
							color[v]=1-color[u];
							qq.push(v);
						}else{
							//already colored
							if(color[v]==color[u]){
								//same color wrong found
								flag=false;
								break;
							}
						}
					}
					if(!flag){
						break;
					}
		        }
		        if(!flag){
		        	break;
		        }
        	}

        }
		

		if(flag){
			cout<<"Correct"<<endl;
		}else{
			cout<<"Wrong"<<endl;
		}
	}
}