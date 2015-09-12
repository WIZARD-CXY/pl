#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	vector<int> need(n);
	vector<int> value(n);

	for(int i=0; i<n; i++){
		cin>>need[i]>>value[i];
	}

	vector<int> dp(m,0);
    
    for(int i=0; i<n; i++){
    	for(int j=m-1; j>=need[i]; j--){
    		dp[j]=max(dp[j],dp[j-need[i]]+value[i]);
    	}
    }

	cout<<dp[m-1]<<endl;
}