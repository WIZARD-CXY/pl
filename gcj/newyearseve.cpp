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

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		cout<<"Case #"<<cas<<": ";

		int b,l,n;
		cin>>b>>l>>n;

        vector<vector<double> > cur,next;
        
        //first level 
        cur.resize(1);
        cur[0].resize(1,b*750.0);
       
        for(int i=1; i<l; i++){
        	next.resize(i+1);

        	for(int j=0; j<=i; j++){
        		next[j].assign(j+1,0.0);
        	}

        	for(int j=0;j<i;j++){
        		for(int k=0; k<=j; k++){
        			if(cur[j][k]>=250.0){
        				//flowaway means the wine flow away
        				double flowaway=cur[j][k]-250.0;

        				//split over three below glass
        				next[j][k]+=flowaway/3;
        				next[j+1][k]+=flowaway/3;
        				next[j+1][k+1]+=flowaway/3;
        			}
        		}
        	}
        	cur=next;
         //    cout<<"---"<<endl;
        	// for(int i=0; i<cur.size(); i++){
        	// 	for(int j=0; j<cur[i].size(); j++){
        	// 		cout<<cur[i][j]<<" ";
        	// 	}
        	// 	cout<<endl;
        	// }
        	// cout<<"---"<<endl;
        }

        int cnt=0;
        for(int i=0; i<l; i++){
    		for(int j=0; j<=i; j++){
    		    cnt++;
    			if(cnt==n){
    				printf("%.7lf\n",min(cur[i][j],250.0));
                    return;
    			}
    		}	
        }
	}

}