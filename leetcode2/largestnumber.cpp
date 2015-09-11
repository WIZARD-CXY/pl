class Solution {
public:
    static bool cmp(const int &a, const int &b){
        string sa=to_string(a);
        string sb=to_string(b);
        
        return sa+sb>sb+sa;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        if(nums[0]==0){
            return "0";
        }
        string res;
        for(auto n :nums){
            res=res+to_string(n);
        }
        return res;
    }
};