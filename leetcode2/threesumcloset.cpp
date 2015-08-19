class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res;
        
        if(nums.size()<3){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            int j=i+1;
            int k=nums.size()-1;
            
            // pick the other two element
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum-target==0){
                    return sum;
                }else if(sum-target>0){
                    if(sum-target<diff){
                        diff=sum-target;
                        res=sum;
                    }
                    k--;
                }else{
                    if(target-sum<diff){
                        diff=target-sum;
                        res=sum;
                    }
                    j++;
                }
            }
        }
        return res;
    }
};