class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }
        if(n==2){
            return abs(nums[1]-nums[0]);
        }
        // cal min and max;
        int Min=nums[0],Max=nums[0];
        
        for(int i=1; i<nums.size(); i++){
            Min=min(nums[i],Min);
            Max=max(nums[i],Max);
        }
        
        //caculate average dist
        int dist=ceil(double(Max-Min)/(n-1));
        vector<vector<int> > bucket(n);
        
        for(int i=0; i<n; i++){
            int idx=(nums[i]-Min)/dist;
            if(bucket[idx].empty()){
                bucket[idx].push_back(nums[i]);
                bucket[idx].push_back(nums[i]);
            }else{
                bucket[idx][0]=min(bucket[idx][0],nums[i]);// bucket[idx][0] store this bucket's min
                bucket[idx][1]=max(bucket[idx][1],nums[i]);// bucket[idx][1] store this bucket's max
            }
        }
        
        int pre=0;
        int res=INT_MIN;
        for(int i=1; i<bucket.size(); i++){
            if(bucket[i].empty()){
                continue;
            }
            int temp=bucket[i][0]-bucket[pre][1];
            res=max(res,temp);
            pre=i;
        }
        
        return res;
    }
};