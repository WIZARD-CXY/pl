class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int n=nums.size();
        
        if(n==0){
            return 0;
        }
        
        vector<int> leftmax(n,INT_MIN);
        vector<int> leftmin(n,INT_MAX);
        
        //leftmax[i] records the nums[0..i] max subarray
        //leftmin[i] records the nums[0..i] min subarray
        
        leftmax[0]=leftmin[0]=nums[0];
        int maxsum=nums[0];// including end element
        int minsum=nums[0];// including end element
        
        for(int i=1; i<n; i++){
            maxsum=max(maxsum+nums[i],nums[i]);
            minsum=min(minsum+nums[i],nums[i]);
            
            leftmax[i]=max(leftmax[i-1],maxsum);
            leftmin[i]=min(leftmin[i-1],minsum);
        }
        
        
        vector<int> rightmax(n,INT_MIN);
        vector<int> rightmin(n,INT_MAX);
        
        //rightmax[i] records the nums[i..n-1] max subarray
        //rightmin[i] records the nums[i..n-1] min subarray
        
        rightmax[n-1]=rightmin[n-1]=nums[n-1];
        maxsum=nums[n-1];//including first element
        minsum=nums[n-1];//including first element
        
        for(int i=n-2; i>=0; i--){
            maxsum=max(maxsum+nums[i],nums[i]);
            minsum=min(minsum+nums[i],nums[i]);
            
            rightmax[i]=max(rightmax[i+1],maxsum);
            rightmin[i]=min(rightmin[i+1],minsum);
        }
        
        //cut the array into 2, i is cutting point
        int res=INT_MIN;
        
        for(int i=0; i<n-1;i++){
            res=max(res,abs(leftmax[i]-rightmin[i+1]));
            res=max(res,abs(leftmin[i]-rightmax[i+1]));
        }
        
        return res;
    }
};

