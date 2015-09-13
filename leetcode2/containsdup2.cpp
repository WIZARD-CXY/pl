class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len =nums.size();
        
        unordered_map<int,int> mm;//key num , value last appear index
        
        for(int i=0; i<len; i++){
            if(mm.find(nums[i])!=mm.end()){
                if(i-mm[nums[i]]<=k){
                   return true;
                }
            }
            //update the last appearance index
            mm[nums[i]]=i;
        }
        return false;
    }
};