class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int len = values.size();
        
        if(len<=2) return true;
        
        vector<vector<int> > d(len, vector<int>(len,0));        
        // f[i][j] means from values[i..j] the max gap value against the rival
        // f[i][j] = max(values[i]-d[i+1][j], values[j]-d[i][j-1]);
        // the first option means I take the leftmost coin
        // the other option means I taker the rightmost coin
        for(int i=0;i<len;i++) {
            d[i][i] = values[i];
        }
        
        for(int i=len-2;i>=0;i--)
        {
            for(int j=i+1;j<len;j++)
            {
                d[i][j] = max(values[i] - d[i+1][j], values[j] - d[i][j-1]);
            }
        }
        return d[0][len-1] > 0;
    }

};
