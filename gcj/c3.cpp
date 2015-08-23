#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;

int n,m;    

#define MAXN 110
#define INF ((1<<30)-1)

int dist[MAXN][MAXN];

void Floyd()
{
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(dist[i][j]>(dist[i][k]+dist[k][j])){

                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

struct ed{
    int a,b,c;
};

int main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++) {
        cout<<"Case #"<<cas<<":"<<endl;
        cin>>n>>m;
      
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dist[i][j] = INF;
            }
        }

        for(int i=0;i<=n;i++){
            dist[i][i] = 0;
        }

        vector<ed> eds;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            
            ed tmp  = ed();
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            eds.push_back(tmp);
            dist[a][b] = dist[b][a] = min(dist[a][b],c);
        }

        Floyd();

        vector<int> res;
        res.clear();

        for (int i=0; i<eds.size(); i++) {
            if(eds[i].c>dist[eds[i].a][eds[i].b]){
                res.push_back(i);
            }
        }
        
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<endl;
        }
    }
    
}

