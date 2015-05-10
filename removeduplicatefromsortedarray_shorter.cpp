class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator last = unique(nums.begin(), nums.end());
        return last-nums.begin();
        
    }
};