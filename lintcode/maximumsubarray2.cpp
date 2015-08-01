class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n=nums.size();
        
        if(n<2){
            return 0;
        }
        
        //lsum[i] means [0..i] max sum
        int lsum[n];
        lsum[0]=nums[0];
        int endmax=nums[0];
        
        // traversal from head to tail
        for(int i=1; i<n; i++){
            endmax=max(endmax+nums[i],nums[i]);
            lsum[i]=max(lsum[i-1],endmax);
        }
        
        // rsum[i] means [i,n-1] maxsum
        // traversal from tail to head
        int rsum[n];
        rsum[n-1]=nums[n-1];
        endmax=nums[n-1];
        
        for(int i=n-2; i>=0; i--){
            endmax=max(endmax+nums[i],nums[i]);
            rsum[i]=max(rsum[i+1],endmax);
        }
        
        int res=INT_MIN;
        // i is cut point
        for(int i=0;i<=n-2;i++){
            res=max(lsum[i]+rsum[i+1],res);
        }
        
        return res;
        
    }
};

