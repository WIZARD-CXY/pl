class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        if(nums.size()==0){
            return res;
        }
        
        //indicate a range start and end
        int s=0,e=0;
        
        while(e<nums.size()){
            if(e+1<nums.size() &&nums[e+1]==nums[e]+1){
                // move end forward 
                e++;
            }else{
                if(s==e){
                    // one element
                    res.push_back(to_string(nums[s]));
                }else{
                    // a range
                    res.push_back(to_string(nums[s])+"->"+to_string(nums[e]));
                }
                e++;
                s=e;
            }
        }
        return res;
    }
};