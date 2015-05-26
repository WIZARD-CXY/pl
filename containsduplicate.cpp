class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mm;
        
        for(int i=0; i<nums.size(); i++){
            if(mm.find(nums[i])==mm.end()){
                mm[nums[i]]=1;
            }else{
                return true;
            }
        }
        return false;
        
    }
};