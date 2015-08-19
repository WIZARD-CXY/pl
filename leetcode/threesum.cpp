class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++){
            //skip same nums[i]
            while(i>0 && i<nums.size() && nums[i]==nums[i-1]){
                i++;
            }
            
            int j=i+1;
            int k=nums.size()-1;
            
            // pick the other two element
            while(j<k){
                //skip the same nums[j]
                if(j>i+1 &&nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                
                //skip the same nums[k]
                if(k<nums.size()-1 && nums[k]==nums[k+1]){
                    k--;
                    continue;
                }
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    j++;
                    k--;
                }else if(sum>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return res;
        
    }
};