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
            auto st=mset.lower_bound((long long)nums[i]-t);
            auto end=mset.upper_bound((long long)nums[i]+t);
            for(auto it=st; it!=end; it++){
                if(abs(nums[i]-*it)<=t){
                    return true;
                }
            }
            
            mset.insert(nums[i]);
        }
        
        return false;
    }
};