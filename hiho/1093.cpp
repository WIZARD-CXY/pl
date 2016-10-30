#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=100005;
int dist[MAXN];
int inq[MAXN];
vector<pair<int,int> > G[MAXN];// we use adjancy-list graph representation
int n,m,s,t;

int main(){
    int n,m,s,t;
    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF){
        for(int i=1; i<=m; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(make_pair(v,w));
            G[v].push_back(make_pair(u,w));
        }

        for(int i=1; i<=n; i++){
            dist[i]=0x7fffffff;
            inq[i]=0;
        }

        dist[s]=0;
        inq[s]=1;

        queue<int> q;
        q.push(s);

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int i=0; i<G[u].size(); i++){
                int v=G[u][i].first;
                int w=G[u][i].second;

                if (dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    if(!inq[v]){
                        inq[v]=1;
                        q.push(v);
                    }
                }
            }

            inq[u]=0;
        }

        printf("%d\n",dist[t]);
    }
}