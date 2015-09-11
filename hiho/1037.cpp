#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<int> > tria(n);

	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			int tmp;
			cin>>tmp;
			tria[i].push_back(tmp);
		}
	}
    //dp[i][j] means the start from i,j the max val we can get
	vector<vector<int> > dp(n,vector<int>(n,0));
    
    //initial the bottom line
	for(int i=0; i<n; i++){
		dp[n-1][i]=tria[n-1][i];
	}

	for(int i=n-2; i>=0; i--){
		for(int j=0;j<=i;j++){
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+tria[i][j];
		}
	}

	cout<<dp[0][0]<<endl;
}