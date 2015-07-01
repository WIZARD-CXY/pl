class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<=1 || k<1 || t<0){
            return false;
        }
        multiset<int> mset;
        
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(i-j>k){
                mset.erase(nums[j++]);
            }
            
            auto iter = mset.lower_bound(nums[i]-t);
            if(iter!=mset.end()){
                if(abs(nums[i]-*iter)<=t){
                    return true;
                }
            }
            mset.insert(nums[i]);
        }
        return false;
        
    }
};