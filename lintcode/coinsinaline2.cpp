class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        
        int n=values.size();
        
        //gap[i] means start from i-th coin the max gap I can win against the other man
        if(n<=2){
            return true;
        }
        vector<int> gap(n);
        
        gap[n-1]=values[n-1];
        gap[n-2]=values[n-1]+values[n-2];
        
        for(int i=n-3; i>=0; i--){
            //take only one coin then other man win gap[i+1]
            //take two coins the other man win gap[i+2]
            gap[i]=max(values[i]-gap[i+1],values[i]+values[i+1]-gap[i+2]);
        }
        
        return gap[0]>0;
    }
};
