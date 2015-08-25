#include <iostream>
#include <vector>
using namespace std;

const int maxn=1e5+5;
vector<int> mine(maxn);
vector<int> mark1(maxn);
vector<int> mark2(maxn);

bool process(vector<int> &mark, int m){

	for(int i=1; i<m; i++){
		if(i==1){
			mark[i]=mine[0]-mark[0];
		}else{
			mark[i]=mine[i-1]-mark[i-1]-mark[i-2];
		}

		if(mark[i]!=0 && mark[i]!=1){
			return false;
		}
	}

	return (mark[m-1]+mark[m-2])==mine[m-1];

}
int main(){
	int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		int m;
		cin>>m;

		for(int i=0; i<m; i++){
			cin>>mine[i];
		}

		//assume first has mine
		mark1[0]=1;
	    bool flag1=process(mark1,m);
	    
	    //assume first has no mine
	    mark2[0]=0;
	    bool flag2=process(mark2,m);

	    int minecnt=0;
	    int nominecnt=0;

	    vector<int> mineidx;
	    vector<int> nomineidx;
	    if(flag1 && flag2){
	        //both valid
	    	for(int i=0; i<m; i++){
	    		if(mark1[i]==mark2[i]){
	    			if(mark1[i]==1){
	    				minecnt++;
	    				mineidx.push_back(i+1);
	    			}else{
	    				nominecnt++;
	    				nomineidx.push_back(i+1);
	    			}
	    		}
	    	}
	    }else if( flag1 || flag2){
	    	if(flag1){
	    		//mark1 valid
		    	for(int i=0; i<m; i++){
		    		if(mark1[i]){
	    				minecnt++;
	    				mineidx.push_back(i+1);
		    		}else{
	    				nominecnt++;
	    				nomineidx.push_back(i+1);
		    		}
		    	}

	    	}else{
	    		//mark2 valid
		    	for(int i=0; i<m; i++){
		    		if(mark2[i]){
	    				minecnt++;
	    				mineidx.push_back(i+1);
		    		}else{
	    				nominecnt++;
	    				nomineidx.push_back(i+1);
		    		}
		    	}

	    	}
	    }

	    cout<<minecnt;
	    for(auto idx :mineidx){
	    	cout<<" "<<idx;
	    }
	    cout<<endl;

	    cout<<nominecnt;
	    for(auto idx : nomineidx){
	    	cout<<" "<<idx;
	    }
	    cout<<endl;

	}
}