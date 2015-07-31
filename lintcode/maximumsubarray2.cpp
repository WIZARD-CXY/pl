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
        int curmax=nums[0];
        
        // traversal from head to tail
        for(int i=1; i<n; i++){
            lsum[i]=max(lsum[i-1]+nums[i],nums[i]);
        }
        
        for(int i=1; i<n; i++){
            if(lsum[i]>curmax){
                curmax=lsum[i];
            }else{
                lsum[i]=curmax;
            }
        }
        
        // rsum[i] means [i,n-1] maxsum
        // traversal from tail to head
        int rsum[n];
        rsum[n-1]=nums[n-1];
        curmax=nums[n-1];
        
        for(int i=n-2; i>=0; i--){
            rsum[i]=max(rsum[i+1]+nums[i],nums[i]);   
        }
        
        for(int i=n-2; i>=0; i--){
            if(rsum[i]>curmax){
                curmax=rsum[i];
            }else{
                rsum[i]=curmax;
            }
        }
        
        int res=INT_MIN;
        // i is cut point
        for(int i=0;i<=n-2;i++){
            res=max(lsum[i]+rsum[i+1],res);
        }
        
        return res;
        
    }
};

