#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

bool cmp(const int &a, const int &b){
	return a>b;
}

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);

	int t,n,m;
	cin>>t;

	for(int i=1; i<=t; i++){
		cin>>n>>m;
		vector<int> tiles(n,0);
	    vector<bool> use(n,0);
	    for(int j=0; j<n; j++){
	    	cin>>tiles[j];
	    }

	    sort(tiles.begin(),tiles.end(),cmp);

	    //greedy algorithm
	    int cnt=1;
	    int remain=m;
	    int j=0;

	    while(remain>0){
	    	int j=0;
	    	while(j<tiles.size() && remain-pow(2,tiles[j])>=0){
	    		if(use[j]){
	    			j++;
	    			continue;
	    		}
	    		remain=remain-pow(2,tiles[j]);
	    		use[j]=1;
    		    j++;
    	    }

    	    int k;
    	    for(k=0; k<n; k++){
    	    	if(use[k]==0){
    	    		break;
    	    	}
    	    }
    	    //all the required tiles have been cut
    	    if(k==n){
    	    	break;
    	    }
	    	if(remain-pow(2,tiles[j])<0){
	    		cnt++;
	    		remain=m;
	    	}
	    }
	    cout<<"Case #"<<i<<": "<<cnt<<endl;
	}
}