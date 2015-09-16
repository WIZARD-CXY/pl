class Solution {
public:
    //two point method
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> res;
        if(n<1){
            return res;
        }
        //range start and end
        int s=0,e=0;
        
        while(e<n){
            if(e+1<n && nums[e+1]==nums[e]+1){
                //move end forward
                e++;
            }else{
                if(s==e){
                    //only one element
                    res.push_back(to_string(nums[s]));
                }else{
                    //a range 
                    res.push_back(to_string(nums[s])+"->"+to_string(nums[e]));
                }
                e++;
                s=e;
            }
        }
        return res;
    }
};