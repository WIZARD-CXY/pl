class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        
        int n=nums.size();
        
        if(n==0){
            return 0;
        }
        
        //maintain a mintemp incase negative * negative got a large positive
        int mintemp=nums[0];
        int maxtemp=nums[0];
        
        int res=nums[0];
        //traversal every element to update minc and maxc
        
        for(int i=1; i<n; i++){
            // not sure mintemp*nums[i] is small, it can be large
            // not sure maxtemp*nums[i] is large, it can be small
            int tempmin=min(mintemp*nums[i],maxtemp*nums[i]);
            int tempmax=max(mintemp*nums[i],maxtemp*nums[i]);
            
            mintemp=min(tempmin,nums[i]);
            maxtemp=max(tempmax,nums[i]);
            
            res=max(maxtemp,res);
        }
        
        return res;
    }
};