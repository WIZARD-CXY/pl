class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        set<vector<int> > tmp;
        vector<int> sol;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++){
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==0){
                   sol.push_back(nums[i]); 
                   sol.push_back(nums[j]); 
                   sol.push_back(nums[k]); 
                   tmp.insert(sol);
                   sol.clear();
                   j++;
                   k--;
                }else if(sum>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        
        vector<vector<int> > res;
        for(auto it=tmp.begin(); it!=tmp.end(); it++){
            res.push_back(*it);
        }
        
        return res;
    }
};

