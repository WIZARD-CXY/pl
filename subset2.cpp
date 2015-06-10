class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        set<vector<int> > tempres;
        
        for(int i=0; i< 1<<n; i++){
            vector<int> temp;
            
            for(int j=0; j<n; j++){
                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            
            tempres.insert(temp);
        }
        
        set<vector<int> >::iterator it=tempres.begin();
        
        for(;it!=tempres.end(); it++){
            res.push_back(*it);
        }
        
        return res;
    }
};