class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        int n=nums.size();
        if(n<2){
            return 0;
        }
        
        if(n==2){
            return abs(nums[1]-nums[0]);
        }
        
        int Min=nums[0],Max=nums[0];
        
        for(int i=1; i<n; i++){
            Min=min(Min,nums[i]);
            Max=max(Max,nums[i]);
        }
        if(Max==Min){
            return 0;
        }
        
        //prepare a size n+1 empty bucket
        vector<vector<int> > bucket(n+1);
        
        // notice the dist maybe zero ,using ceil to avoid this
        int dist=ceil((Max-Min)*1.0/(n-1));
        
        for(int i=0; i<nums.size(); i++){
            int idx=(nums[i]-Min)/dist;
            
            if(bucket[idx].empty()){
                bucket[idx].push_back(nums[i]);
                bucket[idx].push_back(nums[i]);
            }else{
                //bucket[idx][0] store the smallest element in the bucket
                //bucket[idx][1] store the largest element in the bucket
                bucket[idx][0]=min(bucket[idx][0],nums[i]);
                bucket[idx][1]=max(bucket[idx][1],nums[i]);
            }
        }
        
        int pre=0;
        int res=0;
        for(int i=0; i<n+1; i++){
            // traveral the n+1 bucket to find the maximum gap
            if(bucket[i].empty()){
                continue;
            }
            int gap=bucket[i][0]-bucket[pre][1];
            pre=i;
            res=max(res,gap);
        }
        
        return res;
    }
    
};
