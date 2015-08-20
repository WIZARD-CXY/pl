class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        if(n<4){
            return res;
        }
        
        for(int i=0; i<n-3; i++){
            //skip nums[i]
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            
            for(int j=i+1; j<n-2; j++){
                //skip same nums[j]
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                
                int l=j+1;
                int r=n-1;
                
                while(l<r){
                    //skip same nums[l]
                    if(l>j+1 && nums[l]==nums[l-1]){
                        l++;
                        continue;
                    }
                    
                    //skip same nums[r]
                    if(r<n-1 && nums[r]==nums[r+1]){
                        r--;
                        continue;
                    }
                    int sum=nums[i]+nums[j]+nums[l]+nums[r];
                    
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                    }else if(sum>target){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
        
    }
};