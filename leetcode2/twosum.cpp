class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mm;
        
        for(int i=0; i<n; i++){
            auto it=mm.find(target-nums[i]);
            
            if(it!=mm.end()){
                return {it->second,i+1};
            }
            mm[nums[i]]=i+1;
        }
        
        return {-1,-1};
    }
};