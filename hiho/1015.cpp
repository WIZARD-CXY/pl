#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;

	cin>>n;

	for(int cas=0; cas<n; cas++){
		string p,s;
		cin>>p>>s;

		//get next array
		vector<int> next(p.size(),0);

		for(int i=1; i<p.size(); i++){
			int j=next[i-1];

			while(j>0 && p[i]!=p[j]){
				j=next[j-1];
			}

			if(p[i]==p[j]){
				j++;
			}
			p[i]=j;
		}
        
        int ans=0;
        int ssize=s.size();
        int psize=p.size();

        for(int i=0,j=0; i<ssize; i++){
        	if(j<psize && p[j]==s[i]){
        		j++;
        	}else{
        		while(j>0){
        			j=next[j];
        			if(p[j]==s[i]){
        				j++;
        				break;
        			}
        		}
        	}
        	if(j==psize){
        		ans++;
        	}
        }

        cout<<ans<<endl;
	}
}