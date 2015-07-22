class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int res=INT_MAX;
        int dist=INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++){
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target){
                    res=sum;
                    return res;
                }else if(sum>target){
                    if(sum-target<dist){
                        dist=sum-target;
                        res=sum;
                    }
                    k--;
                }else{
                    if(target-sum<dist){
                        dist=target-sum;
                        res=sum;
                    }
                    j++;
                }
            }
        }
        
        return res;
    }
};

