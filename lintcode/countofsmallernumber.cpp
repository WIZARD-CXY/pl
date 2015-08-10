class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> res;
        sort(A.begin(),A.end());
        
        for(auto query : queries){
            auto it=lower_bound(A.begin(),A.end(),query);
            res.push_back(it-A.begin());
        }
        
        return res;
    }
};
