class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> mset;
        
        int j=0;// j is the left bound
        for(int i=0; i<nums.size(); i++){
            //maintain a window of size k
            if(i-j>k){
                mset.erase(nums[j++]);
            }
            //use long long here in case overflow
            //get the lower_bound is enough
            auto st=mset.lower_bound((long long)nums[i]-t);
            
            if(st!=mset.end()){
                if(abs(nums[i]-*st)<=t){
                    return true;
                }
            }
            
            mset.insert(nums[i]);
        }
        
        return false;
    }
};