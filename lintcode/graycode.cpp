class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        
        int size=1<<n;
        
        vector<int> res;
        for(int i=0; i<size; i++){
            // number i 's gray code is i^(i>>1)
            res.push_back(i^(i>>1));
        }
        
        return res;
    }
};
