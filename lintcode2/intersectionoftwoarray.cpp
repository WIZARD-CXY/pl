class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        unordered_set<int> sset;
        unordered_set<int> rres;
        vector<int> res;
        
        for(auto c: nums1){
            sset.insert(c);
        }
        
        for(auto x : nums2){
            if(sset.find(x)!=sset.end()){
                rres.insert(x);
            }
        }
        
        for(auto x : rres){
            res.push_back(x);
        }
        return res;
    }
};