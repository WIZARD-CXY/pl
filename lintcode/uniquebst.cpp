class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        // dp[i] means unique tree number of i nodes
        // really not care about the node val
        vector<int> dp(n+1,0);
        dp[0]=1;// 0 node just one empty tree
        dp[1]=1;// 1 node just one root node
        
        for(int i=2;i<=n;i++){
            for(int j=1; j<=i; j++){
                // if j is root, left subtree node number is j-1;
                // right sub tree node number is i-j
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
