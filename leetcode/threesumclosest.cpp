class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int dist=INT_MAX;
        int res=0;
        
        for(int i=0; i<nums.size(); i++){
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum>target){
                    if(sum-target<dist){
                        dist=sum-target;
                        res=sum;
                    }
                    k--;
                }else if(sum<target){
                    if(target-sum<dist){
                        dist=target-sum;
                        res=sum;
                    }
                    j++;
                }else{
                    res=sum;
                    return res;
                }
                
            }
        }
        return res;
    }
};