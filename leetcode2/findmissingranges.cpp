class Solution {
public:
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        //a dummy element
        int pre=lower-1;
        vector<string> res;
        for(auto n : nums){
            // current is n
            if(n==pre+2){
                res.push_back(to_string(pre+1));
            }else if(n>pre+2){
                res.push_back(to_string(pre+1)+"->"+to_string(n-1));
            }
            pre=n;
        }
        
        //add last element
        if(upper==pre+1){
            res.push_back(to_string(upper));
        }else if(upper>pre+1){
            res.push_back(to_string(pre+1)+"->"+to_string(upper));
        }
        
        return res;
    }
};