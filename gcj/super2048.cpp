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
		cout<<"Case #"<<cas<<":"<<endl;
		int n;
		cin>>n;
		vector<vector<int> > m(n,vector<int>(n,0));

		string dir;
		cin>>dir;

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>m[i][j];
			}
		}
		
		if(dir=="right"){
			// move  0
			for(int row=0; row<n; row++){
				for(int col=n-1; col>=0; col--){
					if(m[row][col]==0){
						//find the first none 0
						int k=col-1;
						while(k>=0 && m[row][k]==0){
							k--;
						}
						if(k>=0){
							swap(m[row][k],m[row][col]);
						}
					}
					
				}
			}

			//then merge
			for(int row=0; row<n; row++){
				
				for(int col=n-1; col>=1; col--){
					
					if(m[row][col]==m[row][col-1]){
						m[row][col]*=2;

						for(int k=col-1; k>=1; k--){
							m[row][k]=m[row][k-1];
						}
						m[row][0]=0;
					}
					
				}
			}

		}else if(dir == "left"){
			// move 0
			for(int row=0; row<n; row++){
				for(int col=0; col<n; col++){
					if(m[row][col]==0){
						//find the first none 0
						int k=col+1;
						while(k>=0 && m[row][k]==0){
							k++;
						}
						if(k<n){
							swap(m[row][k],m[row][col]);
						}
					}
					
				}
			}

			//then merge
			for(int row=0; row<n; row++){
				
				for(int col=0; col<n-1; col++){
					
					if(m[row][col]==m[row][col+1]){
						m[row][col]*=2;

						for(int k=col+1; k<n-1; k++){
							m[row][k]=m[row][k+1];
						}
						m[row][n-1]=0;
					}
					
				}
			}
		}else if(dir=="up"){
			// move 0

			for(int col=0; col<n; col++){
				for(int row=0; row<n; row++){
					if(m[row][col]==0){
						//find the first none 0
						int k=row+1;
						while(k<n && m[k][col]==0){
							k++;
						}
						if(k<n){
							swap(m[k][col],m[row][col]);
						}
					}
					
				}
			}

			//then merge
			
			for(int col=0; col<n; col++){
				
				for(int row=0; row<n-1; row++){
					
					if(m[row][col]==m[row+1][col]){
						m[row][col]*=2;

						for(int k=row+1; k<n-1; k++){
							m[k][col]=m[k+1][col];
						}
						m[n-1][col]=0;
					}
						
				}
			}

		}else{
			// down
			// move 0

			for(int col=0; col<n; col++){
				for(int row=n-1; row>=0; row--){
					if(m[row][col]==0){
						//find the first none 0
						int k=row-1;
						while(k>=0 && m[k][col]==0){
							k--;
						}
						if(k>=0){
							swap(m[k][col],m[row][col]);
						}
					}
					
				}
			}

			//then merge
			
			for(int col=0; col<n; col++){
				
				for(int row=n-1; row>=1; row--){
					
					if(m[row][col]==m[row-1][col]){
						m[row][col]*=2;

						for(int k=row-1; k>=1; k--){
							m[k][col]=m[k-1][col];
						}
						m[0][col]=0;
					}	
				}
			}
		}

		for(int i=0; i<n; i++){
				
				for(int j=0; j<n; j++){
					if(j==0){
						cout<<m[i][j];
					}else{
						cout<<" "<<m[i][j];
					}
				}
				cout<<endl;
			}
	}

}