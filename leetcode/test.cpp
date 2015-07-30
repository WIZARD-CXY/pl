#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int n=A.size();
        vector<vector<bool> > dp(n+1,vector<bool>(m+1,0));
        
        // dp[i][j] means first i element can fit into a j size or not
        // dp[i][j]=dp[i-1][j] || dp[i-1][j-A[i-1]]
        
        dp[0][0]=1;
        
        for(int i=1;i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j]=dp[i-1][j] || (j>=A[i-1] && dp[i-1][j-A[i-1]]);
            }
        }
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=m; i>=0; i--){
            if(dp[n][i]){
                return i;
            }
        }
        
        return 0;
    }
};


int main(){
    Solution sln;
    int m=11;
    
    cout<<sln.backPack(m,{2,3,5,7});
}

