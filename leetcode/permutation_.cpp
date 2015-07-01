class Solution {
public:
    vector<vector<int> > res;

    void permutate(int n, vector<int> &nums,vector<int> &temp,int cur){
        if(cur==n){
            res.push_back(temp);
        }else{
            for(int i=0; i<nums.size(); i++){
                int ok=1;
                for(int j=0; j<cur; j++){
                    if(nums[i]==temp[j]){
                        ok=0;
                    }
                }
                if(ok){
                    temp[cur]=nums[i];
                    permutate(n,nums,temp,cur+1);
                }
                
            }
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> temp(nums.size());
        permutate(nums.size(),nums,temp,0);
        return res;
    }
};