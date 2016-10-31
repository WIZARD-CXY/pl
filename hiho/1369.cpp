#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MAXN=505;
int m,n;
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int p[MAXN];
int a[MAXN];

int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(cap,0,sizeof(cap));
        memset(flow,0,sizeof(flow));

        for(int i=1; i<=m; i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);

            cap[u][v]+=c;
        }

        int max_flow=0;
        
        while(1){
            queue<int> q;
            memset(a,0,sizeof(a));

            a[1]=0x7fffffff;

            q.push(1);

            while(!q.empty()){
                //printf("haha %d\n",q.size());
                int u=q.front();q.pop();
                
                for(int v=1; v<=n; v++){
                    if(!a[v] && cap[u][v]>flow[u][v]){
                        //find new node
                        p[v]=u;
                        q.push(v);
                        a[v]=min(a[u],cap[u][v]-flow[u][v]);
                    }
                }
                if(a[n]){
                    break;
                }
            }

            if (a[n]==0){ //can't find another flow
                break;
            }

            // travesal back
            for(int u=n; u!=1; u=p[u]){
                flow[p[u]][u]+=a[n];
                flow[u][p[u]]-=a[n];
            }
            max_flow+=a[n];
        }

        printf("%d\n",max_flow);
    }
    
}