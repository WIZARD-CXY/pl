class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int> > res;
        if(nums.size()<4){
            return res;
        }
        
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-3; i++){
            for(int j=i+1; j<nums.size()-2;j++){
                int k=j+1;
                int l=nums.size()-1;
                
                while(k<l){
                    int sum=nums[i]+nums[j]+nums[k]+nums[l];
                    
                    if(sum>target){
                        l--;
                    }else if(sum<target){
                        k++;
                    }else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        res.push_back(temp);
                        l--;
                        k++;
                    }
                }
                
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};