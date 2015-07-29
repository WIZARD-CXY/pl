class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        set<vector<int> > tmpres;
        vector<int> nums=S;
        sort(nums.begin(),nums.end());
        
        int n=S.size();
        
        for(int i=0; i<(1<<n); i++){
            vector<int> tmp;
            for(int j=0; j<n; j++){
                if(i &(1<<j)){
                    tmp.push_back(nums[j]);
                }
            }
            
            tmpres.insert(tmp);
        }
        
        vector<vector<int> > res;
        for(auto item : tmpres){
            res.push_back(item);
        }
        
        return res;
    }
};

